#include "stdafx.h"
#include "FreezeBolt.h"
#include "EntityType.h"
#include <ResourceManager\RHandle.h>
static int PPM = 30;
static float RADIAN_TO_DEGREES = 57.2957795f;

FreezeBolt::FreezeBolt(SVector pos, SVector dir, b2World& world) 
	: mSpeed(20),
	mDirection(dir),
	mAngle(0),
	mBody(world, "res/conf/freezeBolt.cfg", pos.getX(), pos.getY()),
	mAlive(true),
	mAnim(res::getTexture("res/img/Anim.png"), "res/conf/anim_ex.cfg", 5.f)
{
	mAnim.getSprite().setOrigin( 64 , 64 );
}

FreezeBolt::~FreezeBolt()
{
}

void FreezeBolt::update(GameData &data, GameStateData &gData,int delta)
{
	mDirection.rotateRad(mBody.getAngle() - mAngle);
	mAngle = mBody.getAngle();

	mBody.setLinearVelocity(b2Vec2(mDirection.getX() * mSpeed, mDirection.getY() * mSpeed));

	mAnim.getSprite().setRotation( mBody.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);
}

void FreezeBolt::draw(RenderList& renderList)
{
	renderList.addSprite(mAnim);
}

void FreezeBolt::addEffect()
{
}

bool FreezeBolt::isAlive()
{
	return mAlive;
}

EntityType FreezeBolt::getType()
{
	return MISC;
}