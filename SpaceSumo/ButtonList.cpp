#include "stdafx.h"
#include "ButtonList.h"

#include "Button.h"
#include <Common\error.h>

ButtonList::ButtonList(int size) : mCurSize(0), mMaxSize(size)
{
	mButtons = new Button*[mMaxSize];
	for(int i = 0; i < mMaxSize; ++i)
	{
		mButtons[i] = 0;
	}
}


ButtonList::~ButtonList()
{
	for(int i = 0; i < mCurSize; ++i)
	{
		delete mButtons[i];
	}
}

void ButtonList::add(Button* button)
{
	SAssert(mCurSize < mMaxSize, "index out of range");
	mButtons[mCurSize] = button;
	++mCurSize;
}

void ButtonList::update(GameData& data, int delta)
{
	for(int i = 0; i < mCurSize; ++i)
	{
		mButtons[i]->update(data);
	}
}

void ButtonList::draw(RenderList& list)
{
	for(int i = 0; i < mCurSize; ++i)
	{
		mButtons[i]->draw(list);
	}
}

void ButtonList::clear()
{
	for(int i = 0; i < mCurSize; ++i)
	{
		delete mButtons[i];
		mButtons[i] = 0;
	}
}