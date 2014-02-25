#ifndef SPACESUMO_RESOURCEMANAGER_SSOUND_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_SSOUND_INCLUDED


class SSoundBuffer;
#include <SFML\Audio\Sound.hpp>
#include "Playable.h"

class SSound: public Playable
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

	virtual bool isPlaying();
	virtual bool hasEnded();
	/* 
		Plays the sound.
		warning; causes an error should the sound not be loaded
	*/
	virtual void play();
	virtual void stop();
	virtual void setDestroy(bool status);
	virtual bool getDestroy();
	virtual void update(GameData& gData);
	/*
		Get the sound buffer of this Sound
		returns: const sf::SoundBuffer& - a reference to this sound's sound buffer 
	*/
	const sf::SoundBuffer& getSoundBuffer() const;
	sf::Sound& getSound();
private:
	bool mDestroy;
	SSound& operator=(const SSound &sp);
	const SSoundBuffer &mSBuf;
	sf::Sound mSound;
	// The version of this instance's sound buffer
	unsigned short mSoundBufVersion;
};

#endif