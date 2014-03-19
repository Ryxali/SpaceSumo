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