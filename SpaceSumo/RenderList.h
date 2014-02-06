#pragma once
#include <list>
#include <SFML\Graphics.hpp>
#include <ResourceManager\Drawable.h>
class RenderList
{
public:
	RenderList();
	void addSprite(Drawable& drawable);
	void render(sf::RenderWindow& renderWindow);

private:
	//typedef std::vector<sf::Sprite*> SpriteVector;
	std::list<Drawable&> mDrawList;
};