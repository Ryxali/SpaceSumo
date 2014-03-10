#include "stdafx.h"
#include "FreezeBolt.h"
#include "EntityType.h"
#include "Frozen.h"
#include <ResourceManager\soundFac.h>
#include <ResourceManager\RHandle.h>
#include "consts.h"

FreezeBolt::FreezeBolt(SVector pos, SVector dir, SVector userSpeed, b2World& world, int projSpeed) 
	: mProjSpeed(projSpeed),
	mDirection(dir),
	mAngle(0),
	mBody(world, "res/conf/freezeBolt.cfg", pos.getX(), pos.getY()),
	mAlive(true),
	mAnim(res::getTexture("res/img/powerup/FreezeBolt/freezebolt.png"), "res/img/powerup/FreezeBolt/freezebolt.cfg", 5.f),
	mShoot(0),
	mTravelling(0)
{
	mBody.setRotation( mDirection.getAngle() );
	mAnim.getSprite().setOrigin( 32 , 32 );
	mBody.getBody()->SetUserData(this);
	float dot = (( userSpeed.getX() * mDirection.getX() + userSpeed.getY() * mDirection.getY()));
	mSpeed = ( b2Vec2( dot * mDirection.getX() , dot * mDirection.getY()));

	mSpeed = ( b2Vec2 ( mSpeed.x / PPM + mDirection.getX() * mProjSpeed, mSpeed.y / PPM + mDirection.getY() * mProjSpeed ));

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
		mShoot = soundFac::createSound("res/sound/freeze/freeze_blast.spf", data.soundlist);
		mTravelling = soundFac::createSound("res/sound/freeze/freeze_travelling.spf", data.soundlist);
		mShoot->play();
		mTravelling->play();
	}

	mAnim.getSprite().rotate(2);
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);

	//deletes the projectile if it's outside the map
	if( (mBody.getPosition().x*PPM < -200 || mBody.getPosition().x*PPM > WINDOW_SIZE.x + 200) || 
		(mBody.getPosition().y*PPM < -200 || mBody.getPosition().y*PPM > WINDOW_SIZE.y + 200))
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