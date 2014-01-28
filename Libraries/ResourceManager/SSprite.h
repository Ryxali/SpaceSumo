#pragma once
#include "STexture.h"
#include <SFML/Graphics/Sprite.hpp>
//#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Drawable.hpp>
class SSprite
{
public:
	SSprite(const STexture &tex);
	~SSprite();
	const sf::Texture& getTexture() const;
	void draw(sf::RenderWindow &win);
private:
	const STexture &mSTex;
	sf::Sprite mSprite;
	unsigned short mTexVersion;
};

