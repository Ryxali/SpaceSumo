#include "stdafx.h"
#include "EffectImp.h"
#include "SpaceManImp.h"

EffectImp::EffectImp() : mIsAlive(true)
{

}

EffectImp::~EffectImp()
{
}

bool EffectImp::isAlive()
{
	return mIsAlive;
}

//TODO add more flags
Flag EffectImp::getFlag_CAN_ROTATE()
{
	return Flag(Flag::CAN_ROTATE);
}

Flag EffectImp::getFlag_CAN_MOVE()
{
	return Flag(Flag::CAN_MOVE);
}

Flag EffectImp::getFlag_CAN_PUSH()
{
	return Flag(Flag::CAN_PUSH);
}

Flag EffectImp::getFlag_CAN_ACTIVATE()
{
	return Flag(Flag::CAN_ACTIVATE);
}