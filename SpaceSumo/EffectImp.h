#pragma once
#include "Flag.h"

class EffectImp
{
public:
	~EffectImp();

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual bool isAlive();
	virtual EffectImp* clone() = 0;
	
	//TODO Add more flags
	virtual Flag getFlag_CAN_ROTATE();
	virtual Flag getFlag_CAN_MOVE();

protected:
	bool mIsAlive;
};

