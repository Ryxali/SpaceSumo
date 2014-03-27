#include "stdafx.h"
#include "Effects.h"
#include "EffectStatus.h"
#include <Common\error.h>
#include "Controller.h"

const int Effects::MAX_SIZE = 50;

class Link
{
public:
	Link(EffectImp* effect);
	~Link();
	bool update(Controller& pController, GameData& data, bool overallChange = false);
	void draw(RenderList& list, SpaceManImp* owner);
	void add(EffectImp* effect);
	void evaluate(EffectStatus& status);
	bool hasExpired();
	void clear();
	Link* getNext();
private:
	EffectImp* effect;
	Link* next;
	
};

Link::Link(EffectImp* effect) 
	: effect(effect), next(0) 
{

}

Link::~Link()
{
	delete effect;
}

bool Link::update(Controller& pController, GameData& data, bool overallChange)
{
	effect->update(pController, data);
	if(next != 0)
	{
		next->update(pController, data);
		if(next->hasExpired())
		{
			Link* tmp = next;
			next = next->getNext();
			delete tmp;
			return true;
		}
	}
	return overallChange;
}

void Link::draw(RenderList& list, SpaceManImp* owner)
{
	effect->draw(list, owner);
	if(next != 0)
		next->draw(list, owner);
}

void Link::add(EffectImp* effect)
{
	if(next == 0)
	{
		next = new Link(effect);
	}
	else
	{
		next->add(effect);
	}
}

void Link::evaluate(EffectStatus& status)
{
	status.addFlag(effect);
	if(next != 0)
		next->evaluate(status);
}

bool Link::hasExpired()
{
	return !effect->isAlive();
}

void Link::clear()
{
	if(next != 0)
	{
		next->clear();
		delete next;
	}
}

Link* Link::getNext()
{
	return next;
}

Effects::Effects() : mSummary(), mCurSize(0), mFirstEffect(0)
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
	bool didChange = false;
	if(mFirstEffect != 0)
	{
		didChange = mFirstEffect->update(pController, data);
		if(mFirstEffect->hasExpired())
		{
			Link* tmp = mFirstEffect;
			mFirstEffect = mFirstEffect->getNext();
			delete tmp;
			didChange = true;
		}
	}
	/*
	int totOffset = 0;
	
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
	}*/

	if(didChange)
	{
		mSummary = EffectStatus();
		evaluate();
	}
}

void Effects::draw(RenderList& renderList, SpaceManImp* owner)
{
	if(mFirstEffect != 0)
		mFirstEffect->draw(renderList, owner);
	/*
	for(int i = 0; i < mCurSize; i++)
	{
		mEffectList[i]->draw(renderList, owner);
	}*/
}

void Effects::addEffect(EffectImp* effect)
{
	if(mFirstEffect != 0)
	{
		mFirstEffect->add(effect);
	}
	else
	{
		mFirstEffect = new Link(effect);
	}
	/*
	SAssert(mCurSize < MAX_SIZE, "index out of bounds");
	mEffectList[mCurSize] = effect;
	++mCurSize;*/
	evaluate();
}

void Effects::clear()
{
	if(mFirstEffect != 0)
	{
		mFirstEffect->clear();
		delete mFirstEffect;
		mFirstEffect = 0;
	}
	/*
	for(int i = 0; i < mCurSize; ++i)
	{
		delete mEffectList[i];
		mEffectList[i] = 0;
	}
	mCurSize = 0;*/
	mSummary = EffectStatus();
	evaluate();

}

EffectStatus& Effects::getStatus()
{
	return mSummary;
}

void Effects::evaluate()
{
	if(mFirstEffect != 0)
		mFirstEffect->evaluate(mSummary);
	/*
	for(int i = 0; i < mCurSize; i++)
	{
		mSummary.addFlag(mEffectList[i]);
	}*/
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