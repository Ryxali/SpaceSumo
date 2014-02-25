#ifndef SPACESUMO_RESOURCEMANAGER_SOUNDBUFFER_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_SOUNDBUFFER_INCLUDED

namespace sf
{
	class SoundBuffer;
};
#ifndef SPACESUMO_RESOURCEMANAGER_RESOURCE_INCLUDED
#include "Resource.h"
#endif
class SSoundBuffer : public Resource
{
public:
	/*
		Constructs the sound buffer (in an unloaded state) with the reference specified
		param: std::string ref - the file reference to the sound file
		usage: SSoundBuffer("Resources/example.ogg");
	*/
	SSoundBuffer(std::string ref);
	// Destructor
	~SSoundBuffer();
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
		get the SoundBuffer this object contains
		returns: const sf::SoundBuffer& - a const reference to the sound buffer contained
		warning; attempting to get an unloaded sound buffer will result in an error
	*/
	const sf::SoundBuffer &getSoundBuffer() const;
private:
	/* 
		Copy constructor needs to be hidden as we don't want
		multiple instances of a single sound buffer
	*/
	SSoundBuffer(const SSoundBuffer &sb);
	// the sfml sound buffer
	sf::SoundBuffer *mSBuffer;
};

#endif