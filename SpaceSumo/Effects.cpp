#include "stdafx.h"
#include "Effects.h"
#include "EffectStatus.h"
#include <Common\error.h>
#include "Controller.h"
const int Effects::MAX_SIZE = 50;

Effects::Effects() : mSummary(), mCurSize(0)
{
	mEffectList = new EffectImp*[MAX_SIZE];
	for(int i = 0; i < MAX_SIZE; ++i)
	{
		mEffectList[i] = 0;
	}
}

Effects::~Effects()
{
}

void Effects::update(Controller& pController, GameData& data)
{
	int totOffset = 0;
	bool didChange = false;
	for(int i = 0; i < mCurSize; ++i)
	{
		mEffectList[i]->update(pController, data);
		if(!mEffectList[i]->isAlive())
		{
			delete mEffectList[i];
			mEffectList[i] = 0;
			floatDown(i);
			didChange = true;
		}
	}
	if(didChange)
	{
		mSummary = EffectStatus();
		evaluate();
	}
}

void Effects::draw(RenderList& renderList, SpaceManImp* owner)
{
	for(int i = 0; i < mCurSize; i++)
	{
		mEffectList[i]->draw(renderList, owner);
	}
}

void Effects::addEffect(EffectImp* effect)
{
	SAssert(mCurSize < MAX_SIZE, "index out of bounds");
	mEffectList[mCurSize] = effect;
	++mCurSize;
	evaluate();
}

void Effects::clear()
{
	for(int i = 0; i < mCurSize; ++i)
	{
		delete mEffectList[i];
		mEffectList[i] = 0;
	}
	mSummary = EffectStatus();
	mCurSize = 0;
	evaluate();

}

EffectStatus& Effects::getStatus()
{
	return mSummary;
}

void Effects::evaluate()
{
	for(int i = 0; i < mCurSize; i++)
	{
		mSummary.addFlag(mEffectList[i]);
	}
}

void Effects::floatDown(int index)
{
	index += 1;
	for(;index < mCurSize; ++index)
	{
		mEffectList[index-1] = mEffectList[index];
		mEffectList[index] = 0;
	}
	--mCurSize;
}