#include "stdafx.h"
#include "PowerUp.h"
#include "EntityType.h"
#include <Common/Config.h>

PowerUp::PowerUp()  :
	mAlive(true),
	mBlinking(false),
	mTimer(0),
	mBlinkStart(0),
	mBlink1(0),
	mBlink2(0),
	mRotate(-1)
{
	Config cfg("res/conf/powerup/Powerup_pickup.cfg");
	mTimer.setDuration(cfg.getValue<int>("Duration"));
	mBlinkStart.setDuration(cfg.getValue<int>("BlinkStart"));
	mBlink1.setDuration(cfg.getValue<int>("Blink1"));
	mBlink2.setDuration(cfg.getValue<int>("Blink2"));
}

PowerUp::~PowerUp()
{
}
void PowerUp::onCollide(Collideable* other)
{

}

void PowerUp::onLeave(Collideable* other)
{

}

enttype::EntityType PowerUp::getType()
{
	return enttype::POWER_UP;
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