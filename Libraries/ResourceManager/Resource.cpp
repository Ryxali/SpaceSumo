#include "Resource.h"
#include <cassert>

Resource::Resource(std::string ref) : mRef(ref), mIsLoaded(false), mVersion(0)
{

}
Resource::~Resource()
{

}

void Resource::load()
{
	if(isLoaded())
		unload();
	mIsLoaded = loadResource();
	assert(isLoaded());
	mVersion++;
}

void Resource::unload()
{
	unloadResource();
	mIsLoaded = false;
}

const std::string& Resource::getRef() const
{
	return mRef;
}

inline bool Resource::isLoaded() const
{
	return mIsLoaded;
}
/*
Get the current version of this Texture. The version changes each
time the texture is loaded.
returns: short - the current version of this Texture
*/
unsigned short Resource::getVersion() const
{
	return mVersion;
}