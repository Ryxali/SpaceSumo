#include "stdafx.h"
#include "SpaceManImp.h"
#include "GameStateData.h"
#include "EntityType.h"
#include "Ability.h"
#include <iostream>
#include <ResourceManager\RHandle.h>
#include <ResourceManager\SSoundBuffer.h>
#include <Common\stringH.h>
#include <Common\Config.h>
#include <ResourceManager\soundFac.h>
#include "Wincon.h"
#include "Head.h"
#include <iostream>
#include "Character_status.h"
#include "EntityType.h"

#include "PowerUp.h"
#include "Effecting.h"

SpaceManImp::SpaceManImp(
	int index,
	Controller& controls,
	SVector pos,
	float startRotation,
	Config& visualData,
	Config& bodyData,
	Config& handData,
	GameData& data,
	Head& head,
	std::string headTexRef) :
	mSpacemanIndex(index),
	mControls(controls),
	mAlive(true),
	mSpawnX(pos.getX()),
	mSpawnY(pos.getY()),
	mHand(*this, handData, data, pos),
	mSpaceman(data.world, bodyData, pos.getX(), pos.getY()),
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
	mRespawn(res::getTexture(visualData.getValue<std::string>("Spawn")+".png"), visualData.getValue<std::string>("Spawn")+".cfg", 8.f),
	mJetpack(soundFac::createSound("res/sound/jetpack/jet.spf")),
	mHead(head),                       
	mRespawning(false),
	mRespawnAngle(startRotation),
	mRespawnAnimTimer(1000),
	mRespawnAnimDraw(false),
	mRespawnAnimSet(false),
	mUseCooldown(bodyData.getValue<int>("useCooldown"))
{
	mHead.getFace().setPersona(headTexRef);
	mSpaceman.setRotation(startRotation);
	mSpaceman.getBody()->SetUserData(this);
	mSpaceman.setAngularVelocity(0);
	mSpaceman.setLinearVelocity(b2Vec2(0.f, 0.f));

	mRespawn.getSprite().setPosition(mSpawnX,mSpawnY);
	mRespawn.getSprite().setRotation(mRespawnAngle);
	mRespawn.getSprite().setOrigin(mRespawn.getSprite().getTextureRect().width/2, mRespawn.getSprite().getTextureRect().height/2-10);
}


SpaceManImp::~SpaceManImp()
{
	delete mAbility;
}

void SpaceManImp::update(GameData &data, GameStateData &gData, int delta)
{
	if( mJetpack == 0)
	{
		mJetpack = soundFac::createSound("res/sound/jetpack/jet.spf");
		mJetpack->setRelativeToListener(false);
		mJetpack->setAttenuation(ATTENUATION);
	}

	mJetpack->setPosition (mSpaceman.getPosition().x*PPM , mSpaceman.getPosition().y*PPM , 0 );

	float fDelta = (float)delta/1000;
	mDirection.rotateRad(mSpaceman.getAngle() - mAngle);
	mAngle = mSpaceman.getAngle();
	mEffects.update(mControls, data);

	if(mSlowDeath)
	{
		if(!(mHead.getScore() > 0))
			mHead.close();
		if( mRespawnTimer.isExpired() && mHead.getScore() > 0)
		{
			if( !mRespawnAnimSet )
			{
				mRespawn.restart();
				mRespawnAnimTimer.reset();
				mRespawnAnimSet = true;
			}
			mRespawnAnimDraw = true;

			if( mRespawnAnimTimer.isExpired() )
			{
				// reset position n'stuff
				mRespawnAnimSet = false;
				mRespawnAnimDraw = false;
				mSpaceman.getBody()->SetTransform(b2Vec2((float32)mSpawnX/PPM, (float32)mSpawnY/PPM), mRespawnAngle*DEGREES_TO_RADIANS);
				mHand.setTransform(b2Vec2((float32)mSpawnX/PPM, (float32)mSpawnY/PPM), mRespawnAngle*DEGREES_TO_RADIANS);
				mSpaceman.setAngularVelocity(0);
				mSpaceman.setLinearVelocity(b2Vec2(0,0));
				mHand.setLinearVelocity(b2Vec2(0,0));
				mSlowDeath = false;
				delete mAbility;
				mAbility = 0;
				mEffects.clear();
			
				mRespawning = true;
			}
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
		

		mSpaceman.applyLinearImpulse( b2Vec2(mDirection.getX() * ( mSpeed * fDelta ),
		mDirection.getY() * ( mSpeed * fDelta )), 
		mSpaceman.getWorldCenter(), true);
		
		if(mJetpack->hasEnded() )
		{
			mJetpack->play();
		}

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
		if(mFixedRotation)
		{
			mSpaceman.setAngularVelocity(mRotationSpeed);
		}
		else
		{
			mSpaceman.applyAngularImpulse( mRotationSpeed * fDelta , true);
		}
		mTurn.setCurrentRow(1);
		
	}

	//turn left
	if(mControls.isActive(Controller::LEFT) && mEffects.getStatus().getFlag_CAN_ROTATE().mStatus)
	{
		if(mFixedRotation)
		{
			mSpaceman.setAngularVelocity(-mRotationSpeed);
		}
		else
		{
			mSpaceman.applyAngularImpulse(-mRotationSpeed * fDelta , true);
		}
		mTurn.setCurrentRow(0);
		
	}	

	if( !mControls.isActive(Controller::RIGHT) && !mControls.isActive(Controller::LEFT))
	{
		//mTurning->stop();
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
			if(mUseCooldown.isExpired())
			{
				mHead.getFace().trigger(status::POWERUP_USE);
				mAbility->activate(mAnim.getSprite().getPosition(), mDirection, SVector(mSpaceman.getLinearVelocity().x * PPM, mSpaceman.getLinearVelocity().y * PPM), gData, data.world);

				delete mAbility;
				mAbility = 0;
				mHead.setPowerup(0);
				mUseCooldown.reset();
			}
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
	if( mRespawnAnimDraw )
	{
		renderList.addSprite(mRespawn);
	}

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
	mHead.getFace().trigger(status::POWERUP_PICKUP);
	mAbility = ability;
	mHead.setPowerup(&mAbility->getImage());
}

bool SpaceManImp::isAlive()
{
	return mAlive;
}
void SpaceManImp::onCollide(Collideable* other)
{
	switch(other->getType())
	{
	case enttype::PLAYER:
		break;
	case enttype::POWER_UP:
		if(isAbilityFree())
			addAbility(static_cast<PowerUp*>(other)->getAbility());
		break;
	case enttype::EFFECTING:
		addEffect(static_cast<Effecting*>(other)->getEffect());
		static_cast<Effecting*>(other)->kill();
		break;
	case enttype::PROJECTILE:
		break;
	}
}

void SpaceManImp::onLeave(Collideable* other)
{
	switch(other->getType())
	{
	case enttype::ARENA:
		slowDeath();
		break;
	case enttype::POWER_UP:
	case enttype::PROJECTILE:
	default:
		break;
	}
}

enttype::EntityType SpaceManImp::getType()
{
	return enttype::PLAYER;
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
	mHead.getFace().trigger(status::DEATH);
	mSlowDeath = true;
	mHead.setPowerup(0);
	mRespawnTimer.reset();
	mJet.setCurrentRow(0);
	mTurn.setCurrentRow(0);
	mJetpack->stop();
}

bool SpaceManImp::isSlowlyDying() const
{
	return mSlowDeath;
}

bool SpaceManImp::respawning()
{
	if( mRespawning )
	{
		mRespawning = false;
		
		return true;
	}
	else
	{
		return false;
	}
}


B2Body& SpaceManImp::getBody()
{
	return mSpaceman;
}

void SpaceManImp::clean(GameData& data)
{
	delete mAbility;
	mAbility = 0;
	mHead.setPowerup(0);
}

Ability* SpaceManImp::getAbility() const
{
	return mAbility;
}

void SpaceManImp::extendArms()
{
	mAnim.setCurrentRow(1);
	mAnim.restart();
	mHand.setMotorSpeed(mPunchForce);
}

void SpaceManImp::retractArms()
{
	mAnim.setCurrentRow(0);
	mHand.setMotorSpeed(-mPunchForce);
}

void SpaceManImp::decreaseLives()
{
	mHead.decreaseLives();
}

bool SpaceManImp::disable(bool status)
{
	return true;
	if(status)
	{
		
			//Flag(Flag::CAN_MOVE, 10, false, 1));
	}

}

Head& SpaceManImp::getHead()
{
	return mHead;
}

int SpaceManImp::getIndex()
{
	return mSpacemanIndex;
}

void SpaceManImp::resetPosition()
{
	mSpaceman.getBody()->SetTransform(b2Vec2((float32)mSpawnX/PPM, (float32)mSpawnY/PPM), mRespawnAngle*DEGREES_TO_RADIANS);
	mHand.setTransform(b2Vec2((float32)mSpawnX/PPM, (float32)mSpawnY/PPM), mRespawnAngle*DEGREES_TO_RADIANS);
	mSpaceman.setAngularVelocity(0);
	mSpaceman.setLinearVelocity(b2Vec2(0,0));
	mHand.setLinearVelocity(b2Vec2(0,0));
}
