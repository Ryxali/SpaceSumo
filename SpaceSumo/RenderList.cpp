#include "stdafx.h"
#include "RenderList.h"
#include <algorithm>

RenderList::RenderList() : mDrawList()
{

}

void RenderList::addSprite(Drawable& drawable)
{
	mDrawList.push_back(drawable);
}

void RenderList::render(sf::RenderWindow& renderWindow)
{
	mDrawList.sort();
	while(mDrawList.begin() != mDrawList.end())
	{
		(mDrawList.front()).draw(renderWindow);
		mDrawList.pop_front();
	}
}
