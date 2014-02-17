#include "stdafx.h"
#include "LHydrogen.h"
#include "Freezer.h"
#include "GameStateData.h"
#include <ResourceManager\RHandle.h>

static int PPM = 30;
static float RADTODEG = 57.2957795f;

LHydrogen::LHydrogen(b2World &world, std::string bodyData, float x, float y) : 
	mAlive(true),
	mBody(world, bodyData, x, y),
	mAnim(res::getTexture("res/img/face1.png"), "res/conf/Test_ikon.cfg", 3.f)
{
	mBody.getBody()->SetUserData(this);
	mAnim.getSprite().setOrigin(64, 64);
}

LHydrogen::~LHydrogen()
{
	
}

void LHydrogen::update(GameData &data, GameStateData &gData, int delta)
{
	mAnim.getSprite().setRotation( mBody.getAngle() * RADTODEG );
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);
}

void LHydrogen::draw(RenderList& renderList)
{
	renderList.addSprite(mAnim);
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

bool LHydrogen::isAlive()
{
	return mAlive;
}