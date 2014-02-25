#include "stdafx.h"
#include "Effect.h"
#include "EffectImp.h"
#include "RenderList.h"

Effect::Effect(EffectImp* imp) : mImp(imp)
{
}

Effect::~Effect()
{
	delete mImp;
}

Effect::Effect(const Effect &e) : mImp(e.mImp->clone())
{
}

Effect& Effect::operator=(const Effect &e)
{
	mImp = e.mImp->clone();
	return *this;
}

void Effect::update(sf::Keyboard::Key& push)
{
	mImp->update(push);
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