#include "stdafx.h"
#include "EffectStatus.h"
#include <Common\error.h>
#include "Effect.h"


EffectStatus::EffectStatus() 
	: mFlag_CAN_MOVE(Flag::CAN_MOVE), mFlag_CAN_ROTATE(Flag::CAN_ROTATE)
{
}

void EffectStatus::addFlag(Effect &effect)
{
	//TODO Add more flags
	if (effect.getFlag_CAN_ROTATE().mSeverity > mFlag_CAN_ROTATE.mSeverity)
	{
		mFlag_CAN_ROTATE = effect.getFlag_CAN_ROTATE();
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

EffectImp* EffectStatus::clone()
{
	return new EffectStatus(*this);
}

//TODO add more flags
Flag EffectStatus::getFlag_CAN_MOVE()
{
	return mFlag_CAN_MOVE;
}

Flag EffectStatus::getFlag_CAN_ROTATE()
{
	return mFlag_CAN_ROTATE;
}