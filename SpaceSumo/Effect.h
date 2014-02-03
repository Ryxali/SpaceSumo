#pragma once
#include "EffectImp.h"

class Effect
{
public:
	Effect(EffectImp*);
	~Effect();

	void update();
	void draw();
	bool isAlive();
	
private:
	EffectImp* mImp;
};

