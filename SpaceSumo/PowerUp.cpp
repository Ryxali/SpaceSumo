#include "stdafx.h"
#include "PowerUp.h"
#include "EntityType.h"

PowerUp::PowerUp()  :
	mAlive(true),
	mTimer(30000)
{

}

PowerUp::~PowerUp()
{
}

EntityType PowerUp::getType()
{
	return EntityType::POWER_UP;
}

bool PowerUp::isAlive()
{
	if(mTimer.isExpired())
		mAlive = false;

	return mAlive;
}