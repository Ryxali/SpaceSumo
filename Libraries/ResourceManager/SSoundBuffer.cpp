#include "SSoundBuffer.h"


#include <Common/error.h>

SSoundBuffer::SSoundBuffer(std::string ref) : Resource(ref)
{
}


SSoundBuffer::~SSoundBuffer()
{
	unload();
}

bool SSoundBuffer::loadResource()
{
	mSBuffer = new sf::SoundBuffer();
	bool success = mSBuffer->loadFromFile(getRef());
	SAssert(success, "Loading failed for some reason.");
	return success;
}

void SSoundBuffer::unloadResource()
{
	delete mSBuffer;
}

const sf::SoundBuffer &SSoundBuffer::getSoundBuffer() const
{
	SAssert(isLoaded(), "You need to load files before playing them.");
	return *mSBuffer;
}