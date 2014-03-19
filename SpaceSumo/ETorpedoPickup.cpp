#include "stdafx.h"
#include "ETorpedoPickup.h"
#include <ResourceManager\RHandle.h>
#include "ETorpedoAbility.h"



ETorpedoPickup::ETorpedoPickup(b2World& world, std::string bodyData, float x, float y) :
	PowerUp(),
	mBody(world, bodyData, x, y),
	mAnim(res::getTexture("res/img/PowerUp/EnergyTorpedo/powerup.png"), "res/img/powerup/EnergyTorpedo/energytorpedo_pickup.cfg", 5.f),
	mSnurrAnim(res::getTexture("res/img/powerup/Ring.png"), "res/img/PowerUp/Snurr.cfg", 6.f)
{
	mBody.getBody()->SetUserData(this);
	mAnim.getSprite().setOrigin( 32 , 32 );
	mSnurrAnim.getSprite().setOrigin( 32 , 32);
	mBlinkStart.reset();
}


ETorpedoPickup::~ETorpedoPickup()
{
}

void ETorpedoPickup::update(GameData&data, GameStateData& gsData, int delta)
{
	mRotate++;
	if(mRotate > 360)
	{
		mRotate = 0;
	}

	mAnim.getSprite().setRotation( mBody.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);
	mSnurrAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);
	mSnurrAnim.getSprite().setRotation(( mBody.getAngle() * RADIAN_TO_DEGREES ) + mRotate );
	

	if(mBlinkStart.isExpired())
	{
		if(mBlink1.isExpired())
		{
			mBlink1.reset();
			mBlink2.reset();
			mBlinking = true;
		}
		else if(mBlink2.isExpired())
		{
			mBlinking = false;
		}
	}
}

void ETorpedoPickup::draw(RenderList& list)
{
	if(!mBlinking)
	{
		list.addSprite(mAnim);
		list.addSprite(mSnurrAnim);
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
