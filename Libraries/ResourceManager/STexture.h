#ifndef SPACE_SUMO_TEXTURE_INCLUDED
#define SPACE_SUMO_TEXTURE_INCLUDED

#include <SFML\Graphics\Texture.hpp>
#include "Resource.h"
#include <Common/stringH.h>

class STexture : public Resource
{
public:
	/*
		Constructs the texture (in an unloaded state) with the reference specified
		param: std::string ref - the file reference to the image file
		usage: SSoundBuffer("Resources/example.png");
	*/
	STexture(std::string ref);
	// Destructor
	~STexture();
	/*
		Loads the resource
		returns: bool - the success of the loading of resource
	*/
	virtual bool loadResource();
	/*
		Unloads the resource
	*/
	virtual void unloadResource();
	/*
		get the Texture this object contains
		returns: const sf::Texture& - a const reference to the Texture contained
		warning; attempting to get an unloaded texture will result in an error
	*/
	const sf::Texture &getTexture() const;
private:
	// Copy constructor needs to be hidden as we don't want multiple instances of a single texture
	STexture(const STexture &tex);
	// The sfml texture
	sf::Texture *mTexture;
};

#endif