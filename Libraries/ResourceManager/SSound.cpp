#ifndef SPACESUMO_RESOURCEMANAGER_SSOUND_INCLUDED
#include "SSound.h"
#endif
#ifndef SPACESUMO_COMMON_ERROR_INCLUDED
#include <Common/error.h>
#endif
#ifndef SPACESUMO_RESOURCEMANAGER_SSOUNDBUFFER_INCLUDED
#include "SSoundBuffer.h"
#endif
SSound::SSound(const SSoundBuffer &sb) : mSound(), mSBuf(sb), mSoundBufVersion(0)
{
}

SSound::SSound(const SSound &sound) : mSound(sound.mSound), mSBuf(sound.mSBuf), mSoundBufVersion(sound.mSoundBufVersion)
{

}

SSound::~SSound()
{
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

const sf::SoundBuffer& SSound::getSoundBuffer() const
{
	SAssert(mSBuf.isLoaded(), "You need to load files before playing them.");
	return mSBuf.getSoundBuffer();
}
