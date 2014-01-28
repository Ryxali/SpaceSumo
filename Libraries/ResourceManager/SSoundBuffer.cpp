#include "SSoundBuffer.h"


#include <cassert>

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
	assert(success);
	return success;
}

void SSoundBuffer::unloadResource()
{
	delete mSBuffer;
}

const sf::SoundBuffer &SSoundBuffer::getSoundBuffer() const
{
	assert(isLoaded());
	return *mSBuffer;
}