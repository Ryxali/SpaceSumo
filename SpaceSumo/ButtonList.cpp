#include "stdafx.h"
#include "ButtonList.h"

#include "Button.h"
#include <Common\error.h>

ButtonList::ButtonList(int size) : mCurSize(0), mMaxSize(size), mMap()
{
	mButtons = new Button*[mMaxSize];
	for(int i = 0; i < mMaxSize; ++i)
	{
		mButtons[i] = 0;
	}
	for( int i = 0; i < 20; i++)
	{
		for ( int j = 0; j < 20; j++ )
		{

			mMap[i][j] = 0; 
		}
	}
}


ButtonList::~ButtonList()
{
	for(int i = 0; i < mCurSize; ++i)
	{
		//delete mButtons[i];
	}
	delete mButtons;
}

void ButtonList::add(Button* button)
{
	SAssert(mCurSize < mMaxSize, "index out of range");
	mButtons[mCurSize] = button;
	++mCurSize;

	SAssert(button->getMapX() <= MAP_WIDTH 
		&& button->getMapY() >= 0 
		&& button->getMapX() >= 0 
		&& button->getMapY() <= MAP_HEIGHT, 
		"mMapX/Y is out of range");

	mMap[button->getMapX()][button->getMapY()] = button;
}

void ButtonList::addObserver(ButtonObserver* observer)
{
	mObserverList.addObserver(observer);
}

void ButtonList::update(GameData& data, int delta)
{
	for(int i = 0; i < mCurSize; ++i)
	{
		mButtons[i]->update(data);
	}

	mObserverList.update(data, delta, *this);
}

void ButtonList::draw(RenderList& list)
{
	for(int i = 0; i < mCurSize; ++i)
	{
		mButtons[i]->draw(list);
	}
	mObserverList.draw(list);
}

void ButtonList::clear()
{
	for(int i = 0; i < mCurSize; ++i)
	{
		delete mButtons[i];
		mButtons[i] = 0;
	}
	mCurSize = 0;

	mObserverList.clear();
}

void ButtonList::clearObservers()
{
	mObserverList.clear();
}

Button* ButtonList::getFirst()
{
	SAssert(mButtons[0] != NULL, "No buttons to start on");
	mButtons[0]->alert();
	return mButtons[0];
}

Button* ButtonList::getUp(int x, int y)
{
	y--;
	if ( y < 0)
	{
		y = MAP_HEIGHT-1;
	}
	while (mMap[x][y] == 0)
	{
		y--;
		if ( y < 0)
		{
			y = MAP_HEIGHT-1;
		}
	}

	return mMap[x][y];
}
Button* ButtonList::getLeft(int x, int y)
{
	x--;
	if ( x < 0)
	{
		x = MAP_WIDTH-1;
	}
	while (mMap[x][y] == 0)
	{
		x--;
		if ( x < 0)
		{
			x = MAP_WIDTH-1;
		}
	}

	return mMap[x][y];
}
Button* ButtonList::getDown(int x, int y)
{
	y++;
	if ( y > MAP_HEIGHT-1)
	{
		y = 0;
	}
	while (mMap[x][y] == 0)
	{
		y++;
		if ( y > MAP_HEIGHT-1)
		{
			y = 0;
		}
	}

	return mMap[x][y];
}
Button* ButtonList::getRight(int x, int y)
{
	x++;
	if ( x > MAP_WIDTH-1)
	{
		x = 0;
	}
	while (mMap[x][y] == 0)
	{
		x++;
		if ( x > MAP_WIDTH-1)
		{
			x = 0;
		}
	}

	return mMap[x][y];
}
