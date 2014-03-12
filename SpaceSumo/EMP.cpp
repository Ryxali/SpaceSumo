#include "stdafx.h"
#include "EMP.h"
#include <ResourceManager\RHandle.h>
#include "EMPAbil.h"

EMP::EMP(b2World &world, std::string bodyData, float x, float y) :
	PowerUp(),
	mBody(world,bodyData, x, y),
	mAnim(res::getTexture("res/img/powerup/LHydrogen.png"), "res/img/powerup/LHydrogen.cfg", 3.f)
{
	mBody.getBody()->SetUserData(this);
	mAnim.getSprite().setOrigin(32, 32);
}

void EMP::update(GameData &data, GameStateData &gData, int delta)
{
	mAnim.getSprite().setRotation( mBody.getAngle() * RADIAN_TO_DEGREES );
	mAnim.getSprite().setPosition( mBody.getWorldCenter().x*PPM, mBody.getWorldCenter().y*PPM);
}

void EMP::draw(RenderList& renderList)
{
	renderList.addSprite(mAnim);
}

Ability* EMP::getAbility()
{
	if(mAlive)
	{
		mAlive = false;
		return new EMPAbil(2000);

	}
	else
	{
		return 0;
	}
}