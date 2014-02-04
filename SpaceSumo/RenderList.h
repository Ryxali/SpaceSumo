#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class RenderList
{
public:
	RenderList();
	void addSprite(sf::Sprite& sprite);
	void render(sf::RenderWindow& renderWindow);

private:
	typedef std::vector<sf::Sprite*> SpriteVector;
	SpriteVector mSpriteVector;

};

