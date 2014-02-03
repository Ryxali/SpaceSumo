#include "stdafx.h"
#include "EffectStatus.h"


EffectStatus::EffectStatus()
{
}

void EffectStatus::addFlag(const Effect &effect)
{
}
//TODO add more flags
Flag EffectStatus::getFlag_CAN_MOVE()
{
	return mFlag_CAN_MOVE;
}

Flag EffectStatus::getFlag_CAN_ALTER_MOVE()
{
	return mFlag_CAN_ALTER_MOVE;
}