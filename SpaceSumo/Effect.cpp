#include "stdafx.h"
#include "Effect.h"
#include "EffectImp.h"
#include "RenderList.h"
#include "GameData.h"


Effect::Effect(EffectImp* imp) : mImp(imp)
{
}

Effect::~Effect()
{
	if(mImp != 0) delete mImp;
}

Effect::Effect(const Effect &e) : mImp(0)
{
	if(e.mImp != 0) mImp = e.mImp;
}

Effect& Effect::operator=(const Effect &e)
{
	if(mImp != 0) delete mImp;
	mImp = e.mImp->clone();
	return *this;
}
/*Effect& Effect::operator=(EffectImp *imp)
{
	if(mImp != 0) delete mImp;
	mImp = imp;
	return *this;
}*/
void Effect::update(sf::Keyboard::Key& push, GameData& data)
{
	mImp->update(push, data);
}

void Effect::draw(RenderList& renderList)
{
	mImp->draw(renderList);
}

bool Effect::isAlive()
{
	return mImp->isAlive();
}

Effect Effect::duplicate()
{
	return Effect(mImp);
}

//TODO Add more flags
Flag Effect::getFlag_CAN_MOVE()
{
	return mImp->getFlag_CAN_MOVE();
}

Flag Effect::getFlag_CAN_ROTATE()
{
	return mImp->getFlag_CAN_ROTATE();
}

Flag Effect::getFlag_CAN_PUSH()
{
	return mImp->getFlag_CAN_PUSH();
}

Flag Effect::getFlag_CAN_ACTIVATE()
{
	return mImp->getFlag_CAN_ACTIVATE();
}

void Effect::reset()
{
	delete mImp;
	mImp = 0;
}