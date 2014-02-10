#ifndef SPACESUMO_RESOURCEMANAGER_SSOUND_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_SSOUND_INCLUDED

class SSoundBuffer;
#include <SFML\Audio\Sound.hpp>

class SSound
{
public:
	/*
		Constructs this object with a reference to a sound buffer
		param: const SSoundBuffer &sb - the sound buffer to link this sound to
	*/
	SSound(const SSoundBuffer &sb);
	/*
		Copy constructor for the SSound
		param: const SSound &sound - the SSound to copy from
	*/
	SSound(const SSound &sound);
	// Destructor
	~SSound();
	/* 
		Plays the sound.
		warning; causes an error should the sound not be loaded
	*/
	void play();
	/*
		Get the sound buffer of this Sound
		returns: const sf::SoundBuffer& - a reference to this sound's sound buffer 
	*/
	const sf::SoundBuffer& getSoundBuffer() const;
private:
	SSound& operator=(const SSound &sp);
	const SSoundBuffer &mSBuf;
	sf::Sound mSound;
	// The version of this instance's sound buffer
	unsigned short mSoundBufVersion;
};

#endif