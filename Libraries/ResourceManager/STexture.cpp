#include "STexture.h"
#include <cassert>

STexture::STexture(std::string ref) : Resource(ref)
{
}


STexture::~STexture()
{
	unload();
}

bool STexture::loadResource()
{
	mTexture = new sf::Texture();
	bool success = mTexture->loadFromFile(getRef());
	assert(success);
	return success;
}

void STexture::unloadResource()
{
	delete mTexture;
}

const sf::Texture &STexture::getTexture() const
{
	assert(isLoaded());
	return *mTexture;
}