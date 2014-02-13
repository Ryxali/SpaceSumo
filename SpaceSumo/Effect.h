#pragma once

class EffectImp;
#include "Flag.h"
class Effect
{
public:
	Effect(EffectImp*);
	~Effect();

	void update();
	void draw();
	bool isAlive();
	Effect duplicate();

	//TODO Add more flags
	Flag getFlag_CAN_MOVE();
	Flag getFlag_CAN_ROTATE();
	
private:
	EffectImp* mImp;
	Effect(const Effect &e);
};

