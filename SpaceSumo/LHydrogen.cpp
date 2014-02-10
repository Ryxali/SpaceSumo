#include "stdafx.h"
#include "LHydrogen.h"
#include "Freezer.h"
#include "GameStateData.h"
#include <ResourceManager\RHandle.h>

LHydrogen::LHydrogen(b2World &world, std::string bodyData) : 
	mAlive(true),
	mBody(world, bodyData, 222, 222),
	mAnim(res::getTexture("res/img/Test_ikon.png"), "res/conf/Test_ikon.cfg")
{

}

LHydrogen::~LHydrogen()
{

}

void LHydrogen::update(GameData &data, GameStateData &gData, int delta)
{

}

void LHydrogen::draw(RenderList& renderList)
{
	mAnim.getSprite().setPosition(mBody.getPosition().x, mBody.getPosition().y);
	renderList.addSprite(mAnim);
}

Ability* LHydrogen::getAbility()
{
	mAbility = new Freezer();
	mAlive = true;
	return mAbility;
}

bool LHydrogen::isAlive()
{
	return mAlive;
}