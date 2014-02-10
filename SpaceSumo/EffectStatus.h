#pragma once
#include "EffectImp.h"
#include "Flag.h"

class Effect;

class EffectStatus :
	public EffectImp
{
public:
	EffectStatus();
	void addFlag(Effect &effect);
	virtual void update();
	virtual void draw();

	//TODO Add more flags
	Flag getFlag_CAN_MOVE();
	Flag getFlag_CAN_ALTER_MOVE();

private:
	Flag mFlag_CAN_MOVE;
	Flag mFlag_CAN_ALTER_MOVE;

};

