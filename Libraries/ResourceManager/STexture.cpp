#include "STexture.h"
#include <cassert>

STexture::STexture(std::string ref) : mRef(ref), mVersion(0), mI
	
	sLoaded(false)
{
}


STexture::~STexture()
{
	unload();
}

void STexture::load()
{
	mVersion++;
	if(isLoaded())
		delete mTexture;
	mTexture = new sf::Texture();
	mIsLoaded = mTexture->loadFromFile(mRef);
	// If there's a problem here then the file failed to load for whatever reason
	assert(isLoaded());
}

void STexture::unload()
{
	if(isLoaded())
	{
		delete mTexture;
	}
	mIsLoaded = false;
}

const sf::Texture &STexture::getTexture() const
{
	assert(isLoaded());
	return *mTexture;
}

const std::string &STexture::getRef() const
{
	return mRef;
}

bool STexture::isLoaded() const
{
	return mIsLoaded;
}

unsigned short STexture::getVersion() const
{
	return mVersion;
}