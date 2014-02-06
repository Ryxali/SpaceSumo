#pragma once
#include <list>
#include <SFML\Graphics.hpp>
#include <ResourceManager\SDrawable.h>

class RenderList
{
public:
	RenderList();
	void addSprite(SDrawable& drawable);
	void render(sf::RenderWindow& renderWindow);

private:
	//typedef std::vector<sf::Sprite*> SpriteVector;
	std::list<SDrawable*> mDrawList;
};