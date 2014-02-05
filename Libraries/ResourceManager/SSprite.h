#pragma once
#include "STexture.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include "Drawable.h"

class SVector;

class SSprite : public Drawable
{
public:
	/*
		Constructs this object with a reference to a Texture
		param: const STexture &tex - the Texture to link this Sprite to
	*/
	SSprite(const STexture &tex);
	/*
		Copy constructor for the SSprite
		param: const SSPrite &sp - the SSprite to copy from
	*/
	SSprite(const SSprite &sp);
	// Destructor
	~SSprite();
	
	const sf::Texture& getTexture() const;
	/* 
		Draws this sprite onto a window
		Causes an error should the Texture not be loaded
	*/
	void draw(sf::RenderWindow &win);

	sf::Sprite& getSprite();

private:

	SSprite& operator=(const SSprite &sp);
	const STexture &mSTex;
	sf::Sprite mSprite;
	// The version of this instance's texture
	unsigned short mTexVersion;
};

