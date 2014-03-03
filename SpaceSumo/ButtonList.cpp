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
		delete mButtons[i];
	}
}

void ButtonList::add(Button* button, int x, int y)
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

Button* ButtonList::getUp(int x, int y)
{
	y--;
	if ( y < 0)
	{
		y = MAP_HEIGHT;
	}
	while (mMap[x][y] == 0)
	{
		y--;
		if ( y < 0)
		{
			y = MAP_HEIGHT;
		}
	}

	return mMap[x][y];
}
Button* ButtonList::getLeft(int x, int y)
{
	x--;
	if ( x < 0)
	{
		x = MAP_WIDTH;
	}
	while (mMap[x][y] == 0)
	{
		x--;
		if ( x < 0)
		{
			x = MAP_WIDTH;
		}
	}

	return mMap[x][y];
}
Button* ButtonList::getDown(int x, int y)
{
	y++;
	if ( y > MAP_HEIGHT)
	{
		y = 0;
	}
	while (mMap[x][y] == 0)
	{
		y++;
		if ( y > MAP_HEIGHT)
		{
			y = 0;
		}
	}

	return mMap[x][y];
}
Button* ButtonList::getRight(int x, int y)
{
	x++;
	if ( x > MAP_WIDTH)
	{
		x = 0;
	}
	while (mMap[x][y] == 0)
	{
		x++;
		if ( x > MAP_WIDTH)
		{
			x = 0;
		}
	}

	return mMap[x][y];
}
