#include "stdafx.h"
#include "Effect.h"


Effect::Effect(EffectImp* imp) : mImp(imp)
{
}

Effect::~Effect()
{
	mImp->~EffectImp();
}

void Effect::update()
{
	mImp->update();
}

void Effect::draw()
{
	mImp->draw();
}

bool Effect::isAlive()
{
	return mImp->isAlive();
}