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

	virtual Flag getFlag_CAN_ROTATE();

private:
	static Config mConfig;
	Timer mTimer;
};

