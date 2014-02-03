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
	
private:
	EffectImp* mImp;
};

