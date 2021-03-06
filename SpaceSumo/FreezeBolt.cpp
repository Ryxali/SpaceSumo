#include "stdafx.h"
#include "FreezeBolt.h"
#include "EntityType.h"
#include "Frozen.h"
#include <ResourceManager\soundFac.h>
#include <ResourceManager\RHandle.h>
#include "consts.h"
#include "SpaceManImp.h"

FreezeBolt::FreezeBolt(SVector pos, SVector dir, SVector userSpeed, b2World& world, int projSpeed) 
	: mDirection(dir),
	mAngle(0),
	mBody(world, "res/conf/powerup/freezebolt.cfg", pos.getX(), pos.getY()),
	mAlive(true),
	mAnim(res::getTexture("res/img/powerup/freezebolt/missile.png"), "res/img/powerup/freezebolt/missile.cfg", 5.f),
	mShoot(0),
	mTravelling(0)
{
	mBody.setRotation( mDirection.getAngle() );
	mAnim.getSprite().setOrigin( 32 , 32 );
	mBody.getBody()->SetUserData(this);

	float dot = (( userSpeed.getX() * mDirection.getX() + userSpeed.getY() * mDirection.getY()));
	mSpeed = ( b2Vec2( dot * mDirection.getX() , dot * mDirection.getY()));

	mSpeed = ( b2Vec2 ( mSpeed.x / PPM + mDirection.getX() * projSpeed, mSpeed.y / PPM + mDirection.getY() * projSpeed ));

	while (mSpeed.Length() < 10 )
	{
		mSpeed = b2Vec2(mSpeed.x + mDirection.getX() / PPM, mSpeed.y + mDirection.getY() / PPM);
	}

	mBody.setLinearVelocity( mSpeed );
}

FreezeBolt::~FreezeBolt()
{
	
}

void FreezeBolt::update(GameData &data, GameStateData &gData, int delta)
{
	
	if( mShoot == 0 && mTravelling == 0)
	{
		
		mTravelling = soundFac::createSound("res/sound/freeze/freeze_travelling.spf");
		mTravelling->setRelativeToListener(false);
		mTravelling->setAttenuation(ATTENUATION);
		mTravelling->setPosition(mBody.getPosition().x*PPM , mBody.getPosition().y*PPM, 0 );

		mShoot = soundFac::createSound("res/sound/freeze/freeze_blast.spf");
		mShoot->setRelativeToListener(false);
		mShoot->setAttenuation(ATTENUATION);
		mShoot->setPosition(mBody.getPosition().x*PPM , mBody.getPosition().y*PPM, 0 );

		mShoot->play();
		mTravelling->play();
	}

	mTravelling->setPosition(mBody.getPosition().x*PPM , mBody.getPosition().y*PPM, 0 );

	mAnim.getSprite().rotate(2);
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);

	//deletes the projectile if it's outside the map
	if( (mBody.getPosition().x*PPM < -1800 || mBody.getPosition().x*PPM > WINDOW_SIZE.x + 1800) || 
		(mBody.getPosition().y*PPM < -1800 || mBody.getPosition().y*PPM > WINDOW_SIZE.y + 1800))
	{
		mAlive = false;
		mTravelling->stop();
	}

}

void FreezeBolt::draw(RenderList& renderList)
{
	renderList.addSprite(mAnim);
}

bool FreezeBolt::isAlive()
{
	return mAlive;
}

EffectImp* FreezeBolt::getEffect()
{
	return new Frozen();
}

void FreezeBolt::kill()
{
	mAlive = false;
	mTravelling->stop();
}