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
#include <ResourceManager\soundFac.h>
#include "Wincon.h"
#include "Head.h"
#include <iostream>

/*
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
	mJetOffset(-37.f),
	mPushDuration(mConfig.getValue<int>("pushDuration")),
	mPushCooldown(mConfig.getValue<int>("pushCooldown")),
	mRespawnTimer(mConfig.getValue<int>("respawnTimer")),
	mAnim(res::getTexture("res/img/Anim.png"), "res/conf/anim_ex.cfg", 5.f),
	mTurn(res::getTexture("res/img/smokesprite.png"), "res/conf/anim_turn.cfg", 6.f),
	mJet(res::getTexture("res/img/blue_jet.png"), "res/conf/anim_jet.cfg", 7.f),
	mAbility(0),
	mPushed(false),
	mSlowDeath(false),
	mAlive(true),
	mJetpack(soundFac::createSound("res/sound/jetpack/jet.spf", data.soundlist)),
	mTurning(soundFac::createSound("res/sound/jetpack/turn.spf", data.soundlist))
{
	//mAnim.getSprite().setOrigin( 64 , 64 );
	//mTurn.getSprite().setOrigin( 64 , 64 );
	//mJet.getSprite().setOrigin( 32 , -37 );

	mSpaceman.setRotation(rotation);
	initializeArms(data.world);
	mSpaceman.getBody()->SetUserData(this);
}*/

SpaceManImp::SpaceManImp(
	Controller& controls,
	SVector pos,
	float startRotation,
	Config& visualData,
	Config& bodyData,
	Config& handData,
	GameData& data) :
	mControls(controls),
	mAlive(true),
	mSpaceman(data.world, bodyData, pos.getX(), pos.getY()),
	mLeftArmJoint(0),
	mLeftArm(0),
	mLeftHand(data.world, handData, pos.getX(), pos.getY()),
	mLeftArmDef(),
	mRightArmJoint(0),
	mRightArm(0),
	mRightHand(data.world, handData, pos.getX(), pos.getY()),
	mRightArmDef(),
	mSpeedLimit(bodyData.getValue<float>("speedLimit")),
	mRotationSpeed(bodyData.getValue<float>("rotationSpeed")),
	mFixedRotation(bodyData.getValue<bool>("fixedRotation")),
	mPunchForce(bodyData.getValue<float>("punchForce")),
	mRespawnTimer(bodyData.getValue<int>("respawnTimer")),
	mPushDuration(bodyData.getValue<int>("pushDuration")),
	mPushCooldown(bodyData.getValue<int>("pushCooldown")),
	mPushed(false),
	mSlowDeath(false),
	mEffects(),
	mAbility(0),
	mSpeed(bodyData.getValue<float>("speed")),
	mDirection(SVector(0.f, -1.f)),
	mAngle(0.f),
	mJetOffset(bodyData.getValue<int>("jetOffset")),
	mAnim(res::getTexture(visualData.getValue<std::string>("Body")+".png"), visualData.getValue<std::string>("Body")+".cfg", 5.f),
	mTurn(res::getTexture(visualData.getValue<std::string>("Smoke")+".png"), visualData.getValue<std::string>("Smoke")+".cfg", 6.f),
	mJet(res::getTexture(visualData.getValue<std::string>("Jet")+".png"), visualData.getValue<std::string>("Jet")+".cfg", 7.f),
	mJetpack(soundFac::createSound("res/sound/jetpack/jet.spf", data.soundlist)),
	mTurning(soundFac::createSound("res/sound/jetpack/turn.spf", data.soundlist))
{
	mSpaceman.setRotation(startRotation);
	initializeArms(data.world);
	mSpaceman.getBody()->SetUserData(this);
	mSpaceman.setAngularVelocity(0);
	mSpaceman.setLinearVelocity(b2Vec2(0.f, 0.f));
}


SpaceManImp::~SpaceManImp()
{
	delete mAbility;
}

void SpaceManImp::update(GameData &data, GameStateData &gData, int delta)
{
	//gData.wincon->update(data, gData, this);
	float fDelta = (float)delta/1000;
	mDirection.rotateRad(mSpaceman.getAngle() - mAngle);
	mAngle = mSpaceman.getAngle();
	mEffects.update(mControls, data);

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
			delete mAbility;
			mAbility = 0;
			mEffects.clear();
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

	if(mFixedRotation && !mControls.isActive(Controller::RIGHT) && !mControls.isActive(Controller::LEFT))
	{
		mSpaceman.setAngularVelocity(0);
	}

	if(mControls.isActive(Controller::FORWARD) && mEffects.getStatus().getFlag_CAN_MOVE().mStatus)
	{
		if(mJetpack->hasEnded())
		{
			mJetpack->play();
		}

		mSpaceman.applyLinearImpulse( b2Vec2(mDirection.getX() * ( mSpeed * fDelta ),
			mDirection.getY() * ( mSpeed * fDelta )), 
			mSpaceman.getWorldCenter(), true);

		//Speed limit
		if(mSpaceman.getLinearVelocity().x < -mSpeedLimit)
		{
			mSpaceman.setLinearVelocity( b2Vec2(-mSpeedLimit, mSpaceman.getLinearVelocity().y));
		}

		if(mSpaceman.getLinearVelocity().x >mSpeedLimit)
		{
			mSpaceman.setLinearVelocity( b2Vec2(mSpeedLimit, mSpaceman.getLinearVelocity().y));
		}

		if(mSpaceman.getLinearVelocity().y > mSpeedLimit)
		{
			mSpaceman.setLinearVelocity(b2Vec2(mSpaceman.getLinearVelocity().x, mSpeedLimit));
		}

		if(mSpaceman.getLinearVelocity().y < -mSpeedLimit)
		{
			mSpaceman.setLinearVelocity(b2Vec2(mSpaceman.getLinearVelocity().x, -mSpeedLimit));
		}

		mJet.setCurrentRow(1);
	}
	else
	{
		mJetpack->stop();
	}


	// turn right
	if(mControls.isActive(Controller::RIGHT) && mEffects.getStatus().getFlag_CAN_ROTATE().mStatus == true)
	{
		mSpaceman.applyAngularImpulse( mRotationSpeed * fDelta , true);
		mTurn.setCurrentRow(1);
		mTurning->play();
	}

	//turn left
	if(mControls.isActive(Controller::LEFT) && mEffects.getStatus().getFlag_CAN_ROTATE().mStatus)
	{
		mSpaceman.applyAngularImpulse( - mRotationSpeed * fDelta , true);
		mTurn.setCurrentRow(0);
		mTurning->play();
	}	

	if( !mControls.isActive(Controller::RIGHT) && !mControls.isActive(Controller::LEFT))
	{
		mTurning->stop();
	}


	// player push
	if(mPushed == true && mPushDuration.isExpired())
	{
		mPushed = false;
		mPushCooldown.reset();
		retractArms();
	}

	if(mControls.isActive(Controller::PUSH) && mEffects.getStatus().getFlag_CAN_PUSH().mStatus && mPushed == false && mPushCooldown.isExpired())
	{
		mPushed = true;
		mPushDuration.reset();
		extendArms();
	} 


	// activate ability
	if(mControls.isActive(Controller::ACTIVATE) && mEffects.getStatus().getFlag_CAN_ACTIVATE().mStatus)
	{
		if(mAbility != 0)
		{
			mAbility->activate(mAnim.getSprite().getPosition(), mDirection, SVector(mSpaceman.getLinearVelocity().x * PPM, mSpaceman.getLinearVelocity().y * PPM), gData, data.world);

			delete mAbility;
			mAbility = 0;
		}
	}
}

void SpaceManImp::draw(RenderList& renderList)
{
	mAnim.getSprite().setOrigin((float)mAnim.getSprite().getTextureRect().width/2, (float)mAnim.getSprite().getTextureRect().height/2);
	mTurn.getSprite().setOrigin((float)mTurn.getSprite().getTextureRect().width/2, (float)mTurn.getSprite().getTextureRect().height/2);
	mJet.getSprite().setOrigin((float)mJet.getSprite().getTextureRect().width/2, (float)mJetOffset);

	mAnim.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mSpaceman.getWorldCenter().x*PPM, mSpaceman.getWorldCenter().y*PPM);

	mTurn.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mTurn.getSprite().setPosition( mSpaceman.getWorldCenter().x*PPM, mSpaceman.getWorldCenter().y*PPM);

	mJet.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mJet.getSprite().setPosition( mSpaceman.getWorldCenter().x*PPM, mSpaceman.getWorldCenter().y*PPM);

	mEffects.draw(renderList, this);
	renderList.addSprite(mAnim);
	renderList.addSprite(mTurn);
	renderList.addSprite(mJet);
}

void SpaceManImp::addEffect(EffectImp* effect)
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
	mJet.setCurrentRow(0);
	mTurn.setCurrentRow(0);
	mJetpack->stop();
}

bool SpaceManImp::isSlowlyDying() const
{
	return mSlowDeath;
}

void SpaceManImp::setScore(int score)
{
	mHead->setScore(score);
}

void SpaceManImp::addScore(int score)
{
	mHead->setScore(mHead->getScore() + score);
}

int SpaceManImp::getScore() const
{
	return mHead->getScore();
}

B2Body& SpaceManImp::getBody()
{
	return mSpaceman;
}

void SpaceManImp::clean(GameData& data)
{
	delete mAbility;
	mAbility = 0;
}

Ability* SpaceManImp::getAbility() const
{
	return mAbility;
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
	mLeftArmJoint->SetMotorSpeed(mPunchForce);
	mRightArmJoint->SetMotorSpeed(mPunchForce);
}

void SpaceManImp::retractArms()
{
	mAnim.setCurrentRow(0);
	mLeftArmJoint->SetMotorSpeed(-mPunchForce);
	mRightArmJoint->SetMotorSpeed(-mPunchForce);

}
