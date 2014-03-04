#include "stdafx.h"
#include "ButtonObserverList.h"
#include "ButtonObserver.h"
#include "RenderList.h"
#include "GameData.h"
#include "ButtonList.h"


ButtonObserverList::ButtonObserverList()
{
}


ButtonObserverList::~ButtonObserverList()
{
	for ( auto it = mObserverList.begin(); it < mObserverList.end(); it++)
	{
		delete *it;
	}
}

void ButtonObserverList::addObserver(ButtonObserver* observer)
{
	mObserverList.emplace_back(observer);
}

void ButtonObserverList::clear()
{
	for ( auto it = mObserverList.begin(); it < mObserverList.end();)
	{
		delete *it;
		it = mObserverList.erase(it);
	}
}

void ButtonObserverList::update(GameData& data, int delta, ButtonList& owner)
{
	for ( auto it = mObserverList.begin(); it < mObserverList.end(); it++)
	{
		(*it)->update(data, delta, owner);
	}
}

void ButtonObserverList::draw(RenderList& renderList)
{
	for ( auto it = mObserverList.begin(); it < mObserverList.end(); it++)
	{
		(*it)->draw(renderList);
	}
}