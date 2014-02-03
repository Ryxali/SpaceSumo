#include "stdafx.h"
#include "EffectImp.h"

EffectImp::~EffectImp()
{
}

bool EffectImp::isAlive()
{
	return mIsAlive;
}

Flag EffectImp::getFlag_CAN_MOVE()
{
	return Flag(Flag::CAN_MOVE);
}

Flag EffectImp::getFlag_CAN_ALTER_MOVE()
{
	return Flag(Flag::CAN_ALTER_MOVE);
}