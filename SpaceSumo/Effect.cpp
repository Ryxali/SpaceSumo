#include "stdafx.h"
#include "Effect.h"


Effect::Effect(EffectImp* imp) : mImp(imp)
{
}

Effect::~Effect()
{
	mImp->~EffectImp();
}

Effect::Effect(const Effect &e) : mImp(e.mImp)
{

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

Effect Effect::duplicate()
{
	return Effect(mImp);
}

Flag Effect::getFlag_CAN_MOVE()
{
	return mImp->getFlag_CAN_MOVE();
}

Flag Effect::getFlag_CAN_ALTER_MOVE()
{
	return mImp->getFlag_CAN_ALTER_MOVE();
}