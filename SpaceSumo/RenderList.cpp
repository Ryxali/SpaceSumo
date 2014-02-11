#include "stdafx.h"
#include "RenderList.h"
#include <ResourceManager\SDrawable.h>

static bool compareZ(const SDrawable* d0, const SDrawable* d1)
{
	return d0->getZ() < d1->getZ();
}

RenderList::RenderList() : mDrawList()
{

}

void RenderList::addSprite(SDrawable& drawable)
{
	mDrawList.push_back(&drawable);
}

void RenderList::render(sf::RenderWindow& renderWindow)
{
	mDrawList.sort(compareZ);
	while(mDrawList.begin() != mDrawList.end())
	{
		(*mDrawList.front()).draw(renderWindow);
		mDrawList.pop_front();
	}
}

