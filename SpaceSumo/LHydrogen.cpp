#include "stdafx.h"
#include "LHydrogen.h"
#include "Freezer.h"

LHydrogen::LHydrogen(b2World world, std::string bodyData) : 
	mPickedUp(false),
	mBody(world, bodyData, 222, 222)
{
	mAbility = new Freezer();
}

LHydrogen::~LHydrogen()
{
	if(mPickedUp = false)
	{
		delete mAbility;
	}
}

void LHydrogen::update(GameData &data, int delta)
{
	if(mPickedUp = true)
	{
		delete this;
	}
}

void LHydrogen::draw(RenderList& renderList)
{
}

Ability* LHydrogen::getAbility()
{
	mPickedUp = true;
	return mAbility;
}