#include "stdafx.h"
#include "FreezeBolt.h"
#include "EntityType.h"
#include <ResourceManager\RHandle.h>
#include "Effect.h"
#include "Frozen.h"
#include <ResourceManager\SSoundBuffer.h>

FreezeBolt::FreezeBolt(SVector pos, SVector dir, b2World& world) 
	: mSpeed(20),
	mDirection(dir),
	mAngle(0),
	mBody(world, "res/conf/freezeBolt.cfg", pos.getX(), pos.getY()),
	mAlive(true),
	mAnim(res::getTexture("res/img/powerup/freezebolt.png"), "res/img/powerup/freezebolt.cfg", 5.f),
	mBlast( new SoundQuene())
{
	mBody.setRotation( mDirection.getAngle() );
	mAnim.getSprite().setOrigin( 32 , 64 );
	mBody.getBody()->SetUserData(this);
	mBody.setLinearVelocity(b2Vec2(mDirection.getX() * mSpeed, mDirection.getY() * mSpeed));
	initializeSounds();
	mBlast->play();
}

FreezeBolt::~FreezeBolt()
{
	delete mBlast;
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

void FreezeBolt::initializeSounds()
{
	mBlast->add( new SSound(res::getSoundBuffer("res/sound/freeze_blast.ogg")));
}