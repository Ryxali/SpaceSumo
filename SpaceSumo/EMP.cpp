#include "stdafx.h"
#include "EMP.h"
#include <ResourceManager\RHandle.h>
#include "EMPAbil.h"

EMP::EMP(b2World &world, std::string bodyData, float x, float y) :
	PowerUp(),
	mBody(world,bodyData, x, y),
	mAnim(res::getTexture("res/img/PowerUp/EMP/EMP.png"), "res/img/PowerUp/EMP/EMP.cfg", 3.f),
	mSnurrAnim(res::getTexture("res/img/powerup/Ring.png"), "res/img/PowerUp/Snurr.cfg", 6.f)
{
	mBody.getBody()->SetUserData(this);
	mAnim.getSprite().setOrigin(32, 32);
	mSnurrAnim.getSprite().setOrigin(32, 32);
	mBlinkStart.reset();
}

void EMP::update(GameData &data, GameStateData &gData, int delta)
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

void EMP::draw(RenderList& renderList)
{
	if(!mBlinking)
	{
		renderList.addSprite(mAnim);
		renderList.addSprite(mSnurrAnim);
	}
}

Ability* EMP::getAbility()
{
	if(mAlive)
	{
		Config config("res/conf/powerup/emp.cfg");

		mAlive = false;
		return new EMPAbil(config.getValue<int>("duration"));

	}
	else
	{
		return 0;
	}
}