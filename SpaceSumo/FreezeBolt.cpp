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
	mAnim(res::getTexture("res/img/powerup/freezebolt.png"), "res/img/powerup/freezebolt.cfg", 5.f),
	mShoot(0)
{
	mBody.setRotation( mDirection.getAngle() );
	mAnim.getSprite().setOrigin( 32 , 64 );
	mBody.getBody()->SetUserData(this);
	float dot = (( userSpeed.getX() * mDirection.getX() + userSpeed.getY() * mDirection.getY()));
	mSpeed = ( b2Vec2( dot * mDirection.getX() , dot * mDirection.getY()));

	mSpeed = ( b2Vec2 ( mSpeed.x / PPM + mDirection.getX() * mProjSpeed, mSpeed.y / PPM + mDirection.getY() * mProjSpeed ));

	while (mSpeed.Length() < 10 )
	{
		mSpeed = b2Vec2(mSpeed.x + mDirection.getX() / PPM, mSpeed.y + mDirection.getY() / PPM);
	}

	mBody.setLinearVelocity( mSpeed );

	
	//mSpeed.Normalize();
	//userSpeed.normalize();

/*		b2Vec2((((float32)userSpeed.getX() * (float32)((mDirection.getX() < 0) ? mDirection.getX()*-1 : mDirection.getX())) + ((float32)mDirection.getX() * (float32)mProjSpeed)) / PPM,
		(((float32)userSpeed.getY() * (float32)((mDirection.getY() < 0) ? mDirection.getY()*-1 : mDirection.getY())) + ((float32)mDirection.getY() * (float32)mProjSpeed)) / PPM )); */
}

FreezeBolt::~FreezeBolt()
{
	
}

void FreezeBolt::update(GameData &data, GameStateData &gData, int delta)
{

	
		//b2Vec2(mProjSpeed * mDirection.getX() + mSpeed.x, mProjSpeed * mDirection.getY() + mSpeed.y ));

	if( mShoot == 0 )
	{
		mShoot = soundFac::createSound("res/sound/freeze/freeze_blast.spf", data.soundlist);
		mShoot->play();
	}

	mAnim.getSprite().setRotation( mDirection.getAngle() + 90);
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);
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
}