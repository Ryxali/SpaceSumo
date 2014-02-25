#ifndef SPACESUMO_RESOURCEMANAGER_SSPRITE_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_SSPRITE_INCLUDED

class STexture;


namespace sf
{
	class RenderWindow;
	class Texture;
};
#include <SFML\Graphics\Sprite.hpp>
#ifndef SPACESUMO_RESOURCEMANAGER_SDRAWABLE_INCLUDED
#include "SDrawable.h"
#endif

class SVector;

class SSprite : public SDrawable
{
public:
	/*
		Constructs this object with a reference to a Texture
		param: const STexture &tex - the Texture to link this Sprite to
	*/
	SSprite(const STexture &tex, float z);
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

	void sync();
	virtual float getZ() const;
	void setZ(float z);
	sf::Sprite& getSprite();

private:

	SSprite& operator=(const SSprite &sp);
	const STexture &mSTex;
	sf::Sprite mSprite;
	// The version of this instance's texture
	unsigned short mTexVersion;

	float mZ;
};

#endif