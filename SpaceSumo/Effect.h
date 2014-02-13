#pragma once
#include "Flag.h"

class EffectImp;

class Effect
{
public:
	Effect(EffectImp*);
	~Effect();
	Effect(const Effect &e);
	Effect& operator=(const Effect &e);
	void update();
	void draw();
	bool isAlive();
	Effect duplicate();

	//TODO Add more flags
	Flag getFlag_CAN_MOVE();
	Flag getFlag_CAN_ROTATE();
	
private:
	EffectImp* mImp;
};

