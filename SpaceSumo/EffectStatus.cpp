#include "stdafx.h"
#include "EffectStatus.h"
#include <Common\error.h>
#include "Effect.h"


EffectStatus::EffectStatus() 
	: mFlag_CAN_MOVE(Flag::CAN_MOVE), mFlag_CAN_ALTER_MOVE(Flag::CAN_ALTER_MOVE)
{
}

void EffectStatus::addFlag(Effect &effect)
{
	//TODO Add more flags
	if (effect.getFlag_CAN_ALTER_MOVE().mSeverity > mFlag_CAN_ALTER_MOVE.mSeverity)
	{
		mFlag_CAN_ALTER_MOVE = effect.getFlag_CAN_ALTER_MOVE();
	}

	if (effect.getFlag_CAN_MOVE().mSeverity > mFlag_CAN_MOVE.mSeverity)
	{
		mFlag_CAN_MOVE = effect.getFlag_CAN_MOVE();
	}
}

void EffectStatus::update()
{
	SAssert(false, "Don't use EffectStatus update()");
}

void EffectStatus::draw()
{
	SAssert(false, "Don't use EffectStatus draw()");
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