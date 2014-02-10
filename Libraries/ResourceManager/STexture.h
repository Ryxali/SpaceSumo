#ifndef SPACESUMO_RESOURCEMANAGER_STEXTURE_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_STEXTURE_INCLUDED

namespace sf
{
	class Texture;
};

#ifndef SPACESUMO_RESOURCEMANAGER_RESOURCE_INCLUDED
#include "Resource.h"
#endif
#include <string>

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