#include "stdafx.h"
#include "RenderList.h"


RenderList::RenderList()
{

}

void RenderList::addSprite(sf::Sprite& sprite)
{
	mSpriteVector.push_back(&sprite);
}

void RenderList::render(sf::RenderWindow& renderWindow)
{
	while(mSpriteVector.begin() != mSpriteVector.end())
	{
		renderWindow.draw((*mSpriteVector.back()));
		mSpriteVector.pop_back();
	}
}
