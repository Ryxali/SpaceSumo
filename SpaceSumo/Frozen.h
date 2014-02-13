#pragma once
#include "effectimp.h"
#include <Common\Timer.h>
#include <Common\Config.h>

class Frozen :
	public EffectImp
{
public:
	Frozen();
	~Frozen();

	virtual void update();
	virtual void draw();
	virtual EffectImp* clone();

	virtual Flag getFlag_CAN_ROTATE();
	virtual Flag getFlag_CAN_MOVE();

private:
	static Config mConfig;
	Timer mTimer;
};

