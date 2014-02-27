#include "stdafx.h"
#include "SpaceManImp.h"
#include "GameStateData.h"
#include "EntityType.h"
#include "Ability.h"
#include <ResourceManager\LoopSound.h>
#include <iostream>
#include <ResourceManager\RHandle.h>
#include <ResourceManager\SSoundBuffer.h>
#include <Common\stringH.h>
#include <Common\Config.h>


Config SpaceManImp::mConfig("res/conf/spaceman.cfg", true);

SpaceManImp::SpaceManImp(sf::Keyboard::Key up,
	sf::Keyboard::Key right,
	sf::Keyboard::Key left,
	sf::Keyboard::Key push,
	sf::Keyboard::Key activate,
	GameData& data, 
	std::string bodyData,
	std::string handData,
	float x, float y, float32 rotation)
	: mUp(up),
	mRight(right),
	mLeft(left),
	mPush(push),
	mActivate(activate),
	mSpaceman(data.world , bodyData, x , y ),
	mLeftHand(data.world, handData, x , y ),
	mRightHand(data.world, handData, x , y ),
	mDirection( 0.0f , -1.0f ),
	mSpeed(mConfig.getValue<float>("speed")),
	mAngle(0.0f),
	mPushTimer(mConfig.getValue<int>("pushCooldown")),
	mRespawnTimer(mConfig.getValue<int>("respawnTimer")),
	mAnim(res::getTexture("res/img/Anim.png"), "res/conf/anim_ex.cfg", 5.f),
	mTurn(res::getTexture("res/img/smokesprite.png"), "res/conf/anim_turn.cfg", 5.f),
	mJet(res::getTexture("res/img/blue_jet.png"), "res/conf/anim_jet.cfg", 6.f),
	mAbility(0),
	mPushing(false),
	mSlowDeath(false),
	mAlive(true),
	mJetpack( new SoundQuene() )
{
	//mAnim.getSprite().setOrigin( 64 , 64 );
	//mTurn.getSprite().setOrigin( 64 , 64 );
	//mJet.getSprite().setOrigin( 32 , -37 );

	mSpaceman.setRotation(rotation);
	initializeArms(data.world);
	initializeSound();
	mSpaceman.getBody()->SetUserData(this);
	data.soundlist.add(mJetpack);
}

SpaceManImp::SpaceManImp(
	Config& playerData,
	Config& spaceManData,
	Config& bodyData,
	Config& handData,
	GameData& data)
	: mUp(str::toKey(playerData.getValue<std::string>("up"))),
	mRight(str::toKey(playerData.getValue<std::string>("right"))),
	mLeft(str::toKey(playerData.getValue<std::string>("left"))),
	mPush(str::toKey(playerData.getValue<std::string>("push"))),
	mActivate(str::toKey(playerData.getValue<std::string>("activate"))),
	mAlive(true),
	mSpaceman(data.world, bodyData, playerData.getValue<float>(""), playerData.getValue<float>("")),
	mLeftArmJoint(0),
	mLeftArm(0),
	mLeftHand(data.world, handData, playerData.getValue<float>(""), playerData.getValue<float>("")),
	mLeftArmDef(),
	mRightArmJoint(0),
	mRightArm(0),
	mRightHand(data.world, handData, playerData.getValue<float>(""), playerData.getValue<float>("")),
	mRightArmDef(),
	mPushTimer(spaceManData.getValue<int>("pushCooldown")),
	mPushing(false),
	mRespawnTimer(spaceManData.getValue<int>("respawnTimer")),
	mSlowDeath(false),
	mEffects(),
	mAbility(0),
	mSpeed(spaceManData.getValue<float>("speed")),
	mDirection(SVector(0.f, -1.f)),
	mAngle(0.f),
	mJetOffset(mConfig.getValue<float>("jetOffset")),
	mAnim(res::getTexture(playerData.getValue<std::string>("")+".png"), playerData.getValue<std::string>("")+".cfg", 5.f),
	mTurn(res::getTexture("res/img/smokesprite.png"), "res/conf/anim_turn.cfg", 6.f),
	mJet(res::getTexture(playerData.getValue<std::string>("")+".png"), playerData.getValue<std::string>("")+".cfg", 7.f)
{
	mSpaceman.setRotation(playerData.getValue<float>("startingRotation"));
	initializeArms(data.world);
	initializeSound();
	mSpaceman.getBody()->SetUserData(this);
}


SpaceManImp::~SpaceManImp()
{
	delete mAbility;
}

void SpaceManImp::update(GameData &data, GameStateData &gData, int delta)
{
	data.soundlist.update(data);
	float fDelta = (float)delta/1000;
	mDirection.rotateRad(mSpaceman.getAngle() - mAngle);
	mAngle = mSpaceman.getAngle();
	mEffects.update(mUp);
	Effect mEffectStatus(mEffects.getStatus());

	if(mSlowDeath)
	{

		if(mRespawnTimer.isExpired())
		{

			//TODO Some kind of better spawn
			mSpaceman.getBody()->SetTransform(b2Vec2((float32)(1920 / 2 /PPM), (float32)(1080 / 2 / PPM)), 0);
			mLeftHand.getBody()->SetTransform(b2Vec2((float32)1920.f / 2.f /PPM, (float32)(1080 / 2.f / PPM)), 0);
			mRightHand.getBody()->SetTransform(b2Vec2((float32)1920.f / 2.f /PPM, (float32)(1080 / 2.f / PPM)), 0);
			mLeftHand.setLinearVelocity(b2Vec2(0,0));
			mRightHand.setLinearVelocity(b2Vec2(0,0));
			mSpaceman.setAngularVelocity(0);
			mSpaceman.setLinearVelocity(b2Vec2(0,0));
			mSlowDeath = false;
		}
		else
		{
			b2Vec2 toTheEdge = b2Vec2(mSpaceman.getWorldCenter() - b2Vec2((float32)(1920 / 2 / PPM),(float32)(1080 / 2 / PPM)));
			toTheEdge.Normalize();

			mSpaceman.applyLinearImpulse( b2Vec2(toTheEdge.x * ( mSpeed * fDelta ),
				toTheEdge.y * ( mSpeed * fDelta )), 
				mSpaceman.getWorldCenter(), true);
			return;
		}
	}

	mTurn.setCurrentRow(2);
	mJet.setCurrentRow(0);

	if(mConfig.getValue<bool>("fixedRotation") && !sf::Keyboard::isKeyPressed(mRight) && !sf::Keyboard::isKeyPressed(mLeft))
	{
		mSpaceman.setAngularVelocity(0);
	}

	if(sf::Keyboard::isKeyPressed(mUp) && mEffectStatus.getFlag_CAN_MOVE().mStatus)
	{
		
		mJetpack->play();
		
		mSpaceman.applyLinearImpulse( b2Vec2(mDirection.getX() * ( mSpeed * fDelta ),
			mDirection.getY() * ( mSpeed * fDelta )), 
			mSpaceman.getWorldCenter(), true);
		
		//Speed limit
		if(mSpaceman.getLinearVelocity().x < -mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity( b2Vec2(-mConfig.getValue<float>("speedLimit"), mSpaceman.getLinearVelocity().y));
		}

		if(mSpaceman.getLinearVelocity().x > mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity( b2Vec2(mConfig.getValue<float>("speedLimit"), mSpaceman.getLinearVelocity().y));
		}

		if(mSpaceman.getLinearVelocity().y > mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity(b2Vec2(mSpaceman.getLinearVelocity().x, mConfig.getValue<float>("speedLimit")));
		}

		if(mSpaceman.getLinearVelocity().y < -mConfig.getValue<float>("speedLimit"))
		{
			mSpaceman.setLinearVelocity(b2Vec2(mSpaceman.getLinearVelocity().x, -mConfig.getValue<float>("speedLimit")));
		}

		mJet.setCurrentRow(1);
	}


	// turn right
	if(sf::Keyboard::isKeyPressed(mRight) && mEffectStatus.getFlag_CAN_ROTATE().mStatus == true)
	{
		mSpaceman.applyAngularImpulse( mConfig.getValue<float>("rotationspeed") * fDelta , true);
		mTurn.setCurrentRow(1);
	}


	//turn left
	if(sf::Keyboard::isKeyPressed(mLeft) && mEffectStatus.getFlag_CAN_ROTATE().mStatus)
	{
		mSpaceman.applyAngularImpulse( - mConfig.getValue<float>("rotationspeed") * fDelta , true);
		mTurn.setCurrentRow(0);
	}	


	// player push
	if(sf::Keyboard::isKeyPressed(mPush) && mEffectStatus.getFlag_CAN_PUSH().mStatus)
	{
		mPushing = true;
		mPushTimer.reset();
	} 

	if( mPushing == true && !mPushTimer.isExpired() )
	{
		extendArms();
	}

	if( mPushTimer.isExpired() )
	{
		retractArms();
		mPushing = false;
	}


	// activate ability
	if(sf::Keyboard::isKeyPressed(mActivate) && mEffectStatus.getFlag_CAN_ACTIVATE().mStatus)
	{
		if(mAbility != 0)
		{
			mAbility->activate(mAnim.getSprite().getPosition(), mDirection, gData, data.world);

			delete mAbility;
			mAbility = 0;
		}
	}
}

void SpaceManImp::draw(RenderList& renderList)
{
	mAnim.getSprite().setOrigin(mAnim.getSprite().getTextureRect().width/2, mAnim.getSprite().getTextureRect().height/2);
	mTurn.getSprite().setOrigin(mTurn.getSprite().getTextureRect().width/2, mTurn.getSprite().getTextureRect().height/2);
	mJet.getSprite().setOrigin(mJet.getSprite().getTextureRect().width/2, mJetOffset);

	mAnim.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mSpaceman.getWorldCenter().x*PPM, mSpaceman.getWorldCenter().y*PPM);

	mTurn.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mTurn.getSprite().setPosition( mSpaceman.getWorldCenter().x*PPM, mSpaceman.getWorldCenter().y*PPM);

	mJet.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mJet.getSprite().setPosition( mSpaceman.getWorldCenter().x*PPM, mSpaceman.getWorldCenter().y*PPM);

	mEffects.draw(renderList);
	renderList.addSprite(mAnim);
	renderList.addSprite(mTurn);
	renderList.addSprite(mJet);
}

void SpaceManImp::addEffect(Effect& effect)
{
	mEffects.addEffect(effect);
}

void SpaceManImp::addAbility(Ability* ability)
{
	mAbility = ability;
}

bool SpaceManImp::isAlive()
{
	return mAlive;
}

EntityType SpaceManImp::getType()
{
	return EntityType::PLAYER;
}

bool SpaceManImp::isAbilityFree()
{
	if(mAbility != 0)
	{
		return false;
	}
	else
		return true;
}

void SpaceManImp::slowDeath()
{
	mSlowDeath = true;
	mRespawnTimer.reset();
}

B2Body& SpaceManImp::getBody()
{
	return mSpaceman;
}

void SpaceManImp::initializeArms(b2World& world)
{
	// Left arm
	mLeftArmDef.bodyA = mLeftHand.getBody();
	mLeftArmDef.bodyB = mSpaceman.getBody();
	mLeftArmDef.collideConnected = false;
	mLeftArmDef.localAxisA.Set( 0 , 1 );
	mLeftArmDef.localAxisA.Normalize();
	mLeftArmDef.localAnchorA.Set( 0 , 0 );
	mLeftArmDef.localAnchorB.Set( -49.f/PPM , 0 );
	mLeftArmDef.enableLimit = true;
	mLeftArmDef.lowerTranslation = 0;
	mLeftArmDef.upperTranslation = 2;
	mLeftArmDef.enableMotor = true;
	mLeftArmDef.maxMotorForce = 300;
	mLeftArmDef.motorSpeed = 0;
	mLeftArmJoint = (b2PrismaticJoint*)world.CreateJoint(&mLeftArmDef);

	// right hand
	mRightArmDef.bodyA = mRightHand.getBody();
	mRightArmDef.bodyB = mSpaceman.getBody();
	mRightArmDef.collideConnected = false;
	mRightArmDef.localAxisA.Set( 0 , 1 );
	mRightArmDef.localAxisA.Normalize();
	mRightArmDef.localAnchorA.Set( 0 , 0 );
	mRightArmDef.localAnchorB.Set( 49.f/PPM , 0 );
	mRightArmDef.enableLimit = true;
	mRightArmDef.lowerTranslation = 0;
	mRightArmDef.upperTranslation = 2;
	mRightArmDef.enableMotor = true;
	mRightArmDef.maxMotorForce = 300;
	mRightArmDef.motorSpeed = 0;
	mRightArmJoint = (b2PrismaticJoint*)world.CreateJoint(&mRightArmDef);
}

void SpaceManImp::extendArms()
{
	mAnim.setCurrentRow(1);
	mLeftArmJoint->SetMotorSpeed(mConfig.getValue<float>("punchforce"));
	mRightArmJoint->SetMotorSpeed(mConfig.getValue<float>("punchforce"));
}

void SpaceManImp::retractArms()
{
	mAnim.setCurrentRow(0);
	mLeftArmJoint->SetMotorSpeed(-mConfig.getValue<float>("punchforce"));
	mRightArmJoint->SetMotorSpeed(-mConfig.getValue<float>("punchforce"));
}

void SpaceManImp::initializeSound()
{
	mJetpack->add(new SSound(res::getSoundBuffer("res/sound/Start.ogg")));
	mJetpack->add(new LoopSound(res::getSoundBuffer("res/sound/Main.ogg")));
	mJetpack->add(new SSound(res::getSoundBuffer("res/sound/End.ogg")));
}
