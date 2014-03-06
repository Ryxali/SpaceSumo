#include "stdafx.h"
#include "EffectStatus.h"
#include <Common\error.h>
#include "Effect.h"


EffectStatus::EffectStatus() 
	: mFlag_CAN_MOVE(Flag::CAN_MOVE), 
	mFlag_CAN_ROTATE(Flag::CAN_ROTATE), 
	mFlag_CAN_PUSH(Flag::CAN_PUSH), 
	mFlag_CAN_ACTIVATE(Flag::CAN_ACTIVATE)
{
}

void EffectStatus::addFlag(EffectImp *effect)
{
	//TODO Add more flags
	if (effect->getFlag_CAN_ROTATE().mSeverity > mFlag_CAN_ROTATE.mSeverity)
	{
		mFlag_CAN_ROTATE = effect->getFlag_CAN_ROTATE();
	}

	if (effect->getFlag_CAN_MOVE().mSeverity > mFlag_CAN_MOVE.mSeverity)
	{
		mFlag_CAN_MOVE = effect->getFlag_CAN_MOVE();
	}

	if (effect->getFlag_CAN_PUSH().mSeverity > mFlag_CAN_PUSH.mSeverity)
	{
		mFlag_CAN_PUSH = effect->getFlag_CAN_PUSH();
	}

	if (effect->getFlag_CAN_ACTIVATE().mSeverity > mFlag_CAN_ACTIVATE.mSeverity)
	{
		mFlag_CAN_ACTIVATE = effect->getFlag_CAN_ACTIVATE();
	}
}

void EffectStatus::update(sf::Keyboard::Key& push, GameData& data)
{
	SAssert(false, "Don't use EffectStatus update()");
}

void EffectStatus::draw(RenderList& renderList, SpaceManImp* owner)
{
	SAssert(false, "Don't use EffectStatus draw()");
}

EffectImp* EffectStatus::clone()
{
	return new EffectStatus(*this);
}

//TODO add more flags
Flag EffectStatus::getFlag_CAN_MOVE()
{
	return mFlag_CAN_MOVE;
}

Flag EffectStatus::getFlag_CAN_ROTATE()
{
	return mFlag_CAN_ROTATE;
}

Flag EffectStatus::getFlag_CAN_PUSH()
{
	return mFlag_CAN_PUSH;
}

Flag EffectStatus::getFlag_CAN_ACTIVATE()
{
	return mFlag_CAN_ACTIVATE;
}