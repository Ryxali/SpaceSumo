#include "stdafx.h"
#include "LHydrogen.h"
#include "Freezer.h"
#include "GameStateData.h"
#include <ResourceManager\RHandle.h>

LHydrogen::LHydrogen(b2World &world, std::string bodyData, float x, float y) : 
	PowerUp(),
	mBody(world, bodyData, x, y),
	mAnim(res::getTexture("res/img/powerup/FreezeBolt/LHydrogen.png"), "res/img/powerup/FreezeBolt/LHydrogen.cfg", 3.f),
	mSnurrAnim(res::getTexture("res/img/powerup/Ring.png"), "res/img/PowerUp/Snurr.cfg", 6.f)
{
	mBody.getBody()->SetUserData(this);
	mAnim.getSprite().setOrigin(32, 32);
	mSnurrAnim.getSprite().setOrigin( 32 , 32);
	mBlinkStart.reset();
}

LHydrogen::~LHydrogen()
{
	
}

void LHydrogen::update(GameData &data, GameStateData &gData, int delta)
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

void LHydrogen::draw(RenderList& renderList)
{
	if(!mBlinking)
	{
		renderList.addSprite(mAnim);
		renderList.addSprite(mSnurrAnim);
	}
}

Ability* LHydrogen::getAbility()
{
	if(mAlive)
	{
		mAbility = new Freezer();
		mAlive = false;
		return mAbility;
	}
	else
	{
		Ability* p = 0;
		return p;
	}

}