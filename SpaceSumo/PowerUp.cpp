#include "stdafx.h"
#include "PowerUp.h"
#include "EntityType.h"

PowerUp::PowerUp()  :
	mAlive(true),
	mBlinking(false),
	mTimer(30000),
	mBlinkStart(24701),
	mBlink1(800),
	mBlink2(400)
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

void PowerUp::kill()
{
	mAlive = false;
}