#include "stdafx.h"
#include "ETorpedoPickup.h"
#include <ResourceManager\RHandle.h>
#include "ETorpedoAbility.h"
#include <iostream>


ETorpedoPickup::ETorpedoPickup(b2World& world, std::string bodyData, float x, float y) :
	PowerUp(),
	mBody(world, bodyData, x, y),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/powerup.png"), "res/img/powerup/EnergyTorpedo/energytorpedo_pickup.cfg", 5.f),
	mDuration(25000),
	mBlink1(800),
	mBlink2(400),
	mDraw(true)
{
	mBody.getBody()->SetUserData(this);
	mAnim.getSprite().setOrigin( 32 , 32 );
	mDuration.reset();
}


ETorpedoPickup::~ETorpedoPickup()
{
}

void ETorpedoPickup::update(GameData&data, GameStateData& gsData, int delta)
{
	mAnim.getSprite().setRotation( mBody.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);

	if(mDuration.isExpired())
	{
		if(mBlink1.isExpired())
		{
			mBlink1.reset();
			mBlink2.reset();
			mDraw = false;
		}
		else if(mBlink2.isExpired())
		{
			mDraw = true;
		}
	}
}

void ETorpedoPickup::draw(RenderList& list)
{
	if(mDraw)
	{
		list.addSprite(mAnim);
	}
}

Ability* ETorpedoPickup::getAbility()
{
	if(mAlive)
	{
		mAbility = new ETorpedoAbility();
		mAlive = false;
		return mAbility;
	}
	else
	{
		Ability* ability = 0;
		return ability;
	}

}
