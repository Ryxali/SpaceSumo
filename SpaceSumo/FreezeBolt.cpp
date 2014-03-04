#include "stdafx.h"
#include "FreezeBolt.h"
#include "EntityType.h"
#include "Effect.h"
#include "Frozen.h"
#include <ResourceManager\soundFac.h>
#include <ResourceManager\RHandle.h>

FreezeBolt::FreezeBolt(SVector pos, SVector dir, b2World& world) 
	: mSpeed(60),
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
	mBody.setLinearVelocity(b2Vec2(mDirection.getX() * mSpeed, mDirection.getY() * mSpeed));
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

EffectImp* FreezeBolt::getEffect(SpaceManImp* owner)
{
	return new Frozen(owner);
}

void FreezeBolt::kill()
{
	mAlive = false;
}