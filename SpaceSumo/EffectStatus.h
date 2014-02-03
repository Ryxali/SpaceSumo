#pragma once
#include "effect.h"
#include "Flag.h"

class EffectStatus :
	public EffectImp
{
public:
	EffectStatus();
	void addFlag(const Effect &effect);

	Flag getFlag_CAN_MOVE();
	Flag getFlag_CAN_ALTER_MOVE();

private:
	Flag::Type mFlag_CAN_MOVE;
	Flag::Type mFlag_CAN_ALTER_MOVE;

};

