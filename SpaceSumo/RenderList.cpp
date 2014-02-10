#include "stdafx.h"
#include "RenderList.h"
#include <ResourceManager\SDrawable.h>

RenderList::RenderList() : mDrawList()
{

}

void RenderList::addSprite(SDrawable& drawable)
{
	mDrawList.push_back(&drawable);
}

void RenderList::render(sf::RenderWindow& renderWindow)
{
	mDrawList.sort();
	while(mDrawList.begin() != mDrawList.end())
	{
		(*mDrawList.front()).draw(renderWindow);
		mDrawList.pop_front();
	}
}
