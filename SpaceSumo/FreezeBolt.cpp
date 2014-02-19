#include "stdafx.h"
#include "FreezeBolt.h"
#include "EntityType.h"
#include <ResourceManager\RHandle.h>
#include "Effect.h"
#include "Frozen.h"
#include <ResourceManager\SSoundBuffer.h>

static int PPM = 30;
static float RADIAN_TO_DEGREES = 57.2957795f;

FreezeBolt::FreezeBolt(SVector pos, SVector dir, b2World& world) 
	: mSpeed(20),
	mDirection(dir),
	mAngle(0),
	mBody(world, "res/conf/freezeBolt.cfg", pos.getX(), pos.getY()),
	mAlive(true),
	mAnim(res::getTexture("res/img/powerup/freezebolt.png"), "res/img/powerup/freezebolt.cfg", 5.f)
{
	mBody.setRotation( mDirection.getAngle() );
	mAnim.getSprite().setOrigin( 32 , 64 );
	mBody.getBody()->SetUserData(this);
	mBody.setLinearVelocity(b2Vec2(mDirection.getX() * mSpeed, mDirection.getY() * mSpeed));
	initializeSound();

	mActivate.play();
}

FreezeBolt::~FreezeBolt()
{

}

void FreezeBolt::update(GameData &data, GameStateData &gData,int delta)
{
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

Effect FreezeBolt::getEffect(SpaceManImp* owner)
{
	return new Frozen(owner);
}


void FreezeBolt::kill()
{
	mAlive = false;
}

void FreezeBolt::initializeSound()
{
	mActivate.setBuffer(res::getSoundBuffer("res/sound/freeze_blast.ogg").getSoundBuffer());
	mHit.setBuffer(res::getSoundBuffer("res/sound/freeze_onhit.ogg").getSoundBuffer());
}