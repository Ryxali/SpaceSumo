#include "stdafx.h"
#include "LHydrogen.h"
#include "Freezer.h"
#include "GameStateData.h"
#include <ResourceManager\RHandle.h>

LHydrogen::LHydrogen(b2World &world, std::string bodyData, float x, float y) : 
	PowerUp(),
	mBody(world, bodyData, x, y),
	mAnim(res::getTexture("res/img/powerup/FreezeBolt/LHydrogen.png"), "res/img/powerup/FreezeBolt/LHydrogen.cfg", 3.f)
{
	mBody.getBody()->SetUserData(this);
	mAnim.getSprite().setOrigin(32, 32);
	mBlinkStart.reset();
}

LHydrogen::~LHydrogen()
{
	
}

void LHydrogen::update(GameData &data, GameStateData &gData, int delta)
{
	mAnim.getSprite().setRotation( mBody.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);

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