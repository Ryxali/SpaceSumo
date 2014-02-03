#pragma once
#include "Flag.h"

class EffectImp
{
public:
	~EffectImp();

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual bool isAlive();
	
	//TODO Add more flags
	virtual Flag getFlag_CAN_MOVE();
	virtual Flag getFlag_CAN_ALTER_MOVE();

protected:
	bool mIsAlive;
};

