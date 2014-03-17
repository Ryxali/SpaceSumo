#ifndef SPACESUMO_RESOURCEMANAGER_SSOUND_INCLUDED
#include "SSound.h"
#endif
#ifndef SPACESUMO_COMMON_ERROR_INCLUDED
#include <Common/error.h>
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_SSOUNDBUFFER_INCLUDED
#include "SSoundBuffer.h"
#endif
SSound::SSound(const SSoundBuffer &sb) : mSound(), mSBuf(sb), mSoundBufVersion(0), mDestroy(false)
{
	
}

SSound::SSound(const SSound &sound) : mSound(sound.mSound), mSBuf(sound.mSBuf), mSoundBufVersion(sound.mSoundBufVersion), mDestroy(sound.mDestroy)
{
}

SSound::~SSound()
{
}

bool SSound::isPlaying()
{
	if(mSound.getStatus() == sf::Sound::Status::Playing )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SSound::hasEnded()
{
	if(mSound.getStatus() == sf::Sound::Status::Stopped )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SSound::play()
{
	if(mSoundBufVersion != mSBuf.getVersion())
	{
		mSound.setBuffer(getSoundBuffer());
		mSoundBufVersion = mSBuf.getVersion();
	}
	SAssert(mSBuf.isLoaded(), "The sound buffer isn't loaded");
	mSound.play();
}

void SSound::stop()
{
	if(mSoundBufVersion != mSBuf.getVersion())
	{
		mSound.setBuffer(getSoundBuffer());
		mSoundBufVersion = mSBuf.getVersion();
	}
	SAssert(mSBuf.isLoaded(), "The sound buffer isn't loaded");
	mSound.stop();
}

void SSound::forceStop()
{
	stop();
}

void SSound::setDestroy(bool status)
{
	mDestroy = status;
}

bool SSound::getDestroy()
{
	return mDestroy;
}


void SSound::update()
{

}

const sf::SoundBuffer& SSound::getSoundBuffer() const
{
	SAssert(mSBuf.isLoaded(), "You need to load files before playing them.");
	return mSBuf.getSoundBuffer();
}

sf::Sound& SSound::getSound()
{
	return mSound;
}

void SSound::setRelativeToListener(bool state)
{
	mSound.setRelativeToListener(state);
}

void SSound::setAttenuation(float atten)
{
	mSound.setAttenuation(atten);
}


void SSound::setPosition(float x, float y, float z)
{
	mSound.setPosition(x, y, z);
}