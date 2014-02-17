#include "stdafx.h"
#include "SpaceManImp.h"
#include <ResourceManager\RHandle.h>
#include "GameStateData.h"
#include "EntityType.h"
#include "Ability.h"
#include <iostream>
static int PPM = 30;
static float RADIAN_TO_DEGREES = 57.2957795f;

Config SpaceManImp::mConfig("res/conf/spaceman.cfg", true);

SpaceManImp::SpaceManImp(sf::Keyboard::Key up,
	sf::Keyboard::Key right,
	sf::Keyboard::Key left,
	sf::Keyboard::Key push,
	sf::Keyboard::Key activate,
	b2World& world, std::string bodyData,
	std::string handData,
	float x, float y, float32 rotation)
	: mUp(up),
	mRight(right),
	mLeft(left),
	mPush(push),
	mActivate(activate),
	mSpaceman(world , bodyData, x , y ),
	mLeftHand(world, handData, x , y ),
	mRightHand(world, handData, x , y ),
	mDirection( 0.0f , -1.0f ),
	mSpeed(mConfig.getValue<float>("speed")),
	mAngle(0.0f),
	mRespawnTimer(mConfig.getValue<int>("respawnTimer")),
	mAnim(res::getTexture("res/img/Anim.png"), "res/conf/anim_ex.cfg", 5.f),
	mTurn(res::getTexture("res/img/smokesprite.png"), "res/conf/anim_turn.cfg", 5.f),
	mJet(res::getTexture("res/img/blue_jet.png"), "res/conf/anim_jet.cfg", 6.f),
	mAbility(0),
	mSlowDeath(false)
{
	mAnim.getSprite().setOrigin( 64 , 64 );
	mTurn.getSprite().setOrigin( 64 , 64 );
	mJet.getSprite().setOrigin( 32 , -37 );
	
	mSpaceman.setRotation(rotation);
	initializeArms(world);
	mSpaceman.getBody()->SetUserData(this);
}


SpaceManImp::~SpaceManImp()
{

}

void SpaceManImp::update(GameData &data, GameStateData &gData, int delta)
{


	float fDelta = (float)delta/1000;
	mDirection.rotateRad(mSpaceman.getAngle() - mAngle);
	mAngle = mSpaceman.getAngle();
	mEffects.update();
	Effect mEffectStatus(mEffects.getStatus());

	if(mSlowDeath)
	{
		b2Vec2 toTheEdge = b2Vec2(mSpaceman.getWorldCenter() - b2Vec2(1920 / 2 / PPM, 1080 / 2 / PPM));
		toTheEdge.Normalize();

		mSpaceman.applyLinearImpulse( b2Vec2(toTheEdge.x * ( mSpeed * fDelta ),
									toTheEdge.y * ( mSpeed * fDelta )), 
									mSpaceman.getWorldCenter(), true);

		if(mRespawnTimer.isExpired())
		{
			mSpaceman.setAngularVelocity(0);
			//mSpaceman.setLinearVelocity(0);
			mSlowDeath = false;
		}

		return;
	}

	mTurn.setCurrentRow(2);
	mJet.setCurrentRow(0);

	if(mConfig.getValue<bool>("fixedRotation") && !sf::Keyboard::isKeyPressed(mRight) && !sf::Keyboard::isKeyPressed(mLeft))
	{
		mSpaceman.setAngularVelocity(0);
	}


	if(sf::Keyboard::isKeyPressed(mUp) && mEffectStatus.getFlag_CAN_MOVE().mStatus)
	{
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

	

	if(sf::Keyboard::isKeyPressed(mRight) && mEffectStatus.getFlag_CAN_ROTATE().mStatus == true)
	{
		mSpaceman.applyAngularImpulse( mConfig.getValue<float>("rotationspeed") * fDelta , true);
		mTurn.setCurrentRow(1);
	}

	if(sf::Keyboard::isKeyPressed(mLeft) && mEffectStatus.getFlag_CAN_ROTATE().mStatus)
	{
		mSpaceman.applyAngularImpulse( - mConfig.getValue<float>("rotationspeed") * fDelta , true);
		mTurn.setCurrentRow(0);
	}
	
	if(sf::Keyboard::isKeyPressed(mPush) && mEffectStatus.getFlag_CAN_PUSH().mStatus)
	{
  		mAnim.setCurrentRow(1);
		mLeftArmJoint->SetMotorSpeed(20);
		mRightArmJoint->SetMotorSpeed(20);
		
	} 
	else
	{
		mAnim.setCurrentRow(0);
		mLeftArmJoint->SetMotorSpeed(-20);
		mRightArmJoint->SetMotorSpeed(-20);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && mEffectStatus.getFlag_CAN_ACTIVATE().mStatus)
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
	mAnim.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mSpaceman.getWorldCenter().x*PPM, mSpaceman.getWorldCenter().y*PPM);

	mTurn.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mTurn.getSprite().setPosition( mSpaceman.getWorldCenter().x*PPM, mSpaceman.getWorldCenter().y*PPM);

	mJet.getSprite().setRotation( mSpaceman.getAngle() * RADIAN_TO_DEGREES );
	mJet.getSprite().setPosition( mSpaceman.getWorldCenter().x*PPM, mSpaceman.getWorldCenter().y*PPM);

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

void SpaceManImp::initializeArms(b2World& world)
{
	// Left arm
	mLeftArmDef.bodyA = mLeftHand.getBody();
	mLeftArmDef.bodyB = mSpaceman.getBody();
	mLeftArmDef.collideConnected = false;
	mLeftArmDef.localAxisA.Set( 0 , 1 );
	mLeftArmDef.localAxisA.Normalize();
	mLeftArmDef.localAnchorA.Set( 0 , 0 );
	mLeftArmDef.localAnchorB.Set( -49/PPM , 0 );
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
	mRightArmDef.localAnchorB.Set( 49/PPM , 0 );
	mRightArmDef.enableLimit = true;
	mRightArmDef.lowerTranslation = 0;
	mRightArmDef.upperTranslation = 2;
	mRightArmDef.enableMotor = true;
	mRightArmDef.maxMotorForce = 300;
	mRightArmDef.motorSpeed = 0;
	mRightArmJoint = (b2PrismaticJoint*)world.CreateJoint(&mRightArmDef);
}

