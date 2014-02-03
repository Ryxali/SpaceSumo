#pragma once
#include "EffectImp.h"

class Effect
{
public:
	Effect(EffectImp*);
	~Effect();
	Effect(const Effect &e);

	void update();
	void draw();
	bool isAlive();
	Effect duplicate();

	//TODO Add more flags
	Flag getFlag_CAN_MOVE();
	Flag getFlag_CAN_ALTER_MOVE();
	
private:
	EffectImp* mImp;
};

