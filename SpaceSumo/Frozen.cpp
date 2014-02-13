#include "stdafx.h"
#include "Frozen.h"

Config Frozen::mConfig("res/conf/frozen.cfg", true);

Frozen::Frozen() : mTimer(mConfig.getValue<int>("duration"))
{
}

Frozen::~Frozen()
{
}

void Frozen::update()
{
	if (mTimer.isExpired())
	{
		mIsAlive = false;
	}
}

void Frozen::draw()
{
}

Flag Frozen::getFlag_CAN_ROTATE()
{
	return Flag(Flag::CAN_ROTATE, 10, false, 1);
}