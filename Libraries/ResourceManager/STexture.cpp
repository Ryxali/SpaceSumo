#include "STexture.h"
#include <Common/error.h>

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
	SAssert(success, "Couldn't load texture.");
	return success;
}

void STexture::unloadResource()
{
	delete mTexture;
}

const sf::Texture &STexture::getTexture() const
{
	SAssert(isLoaded(), "Texture isn't loaded.");
	return *mTexture;
}