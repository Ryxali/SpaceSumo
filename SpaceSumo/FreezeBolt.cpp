#include "stdafx.h"
#include "FreezeBolt.h"
#include "EntityType.h"
#include "Frozen.h"
#include <ResourceManager\soundFac.h>
#include <ResourceManager\RHandle.h>

FreezeBolt::FreezeBolt(SVector pos, SVector dir, SVector userSpeed, b2World& world, int projSpeed) 
	: mSpeed(projSpeed),
	mDirection(dir),
	mAngle(0),
	mBody(world, "res/conf/freezeBolt.cfg", pos.getX(), pos.getY()),
	mAlive(true),
	mAnim(res::getTexture("res/img/powerup/FreezeBolt/freezebolt.png"), "res/img/powerup/FreezeBolt/freezebolt.cfg", 5.f),
	mShoot(0)
{
	mBody.setRotation( mDirection.getAngle() );
	mAnim.getSprite().setOrigin( 32 , 32 );
	mBody.getBody()->SetUserData(this);
	mBody.setLinearVelocity(b2Vec2(mDirection.getX() * mSpeed, mDirection.getY() * mSpeed));
	mSpeed += userSpeed.getX() * dir.getX() + userSpeed.getY() * dir.getY();
}

FreezeBolt::~FreezeBolt()
{
	
}

void FreezeBolt::update(GameData &data, GameStateData &gData, int delta)
{
	
	if( mShoot == 0 )
	{
		mShoot = soundFac::createSound("res/sound/freeze/freeze_blast.spf", data.soundlist);
		mShoot->play();
	}

	//mAnim.getSprite().setRotation( mDirection.getAngle() + 90);
	mAnim.getSprite().rotate(2);
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