#include "SSound.h"
#include <cassert>

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
	assert(mSBuf.isLoaded());
	if(mSoundBufVersion != mSBuf.getVersion())
	{
		mSound.setBuffer(getSoundBuffer());
		mSoundBufVersion = mSBuf.getVersion();
	}
	mSound.play();
}

const sf::SoundBuffer& SSound::getSoundBuffer() const
{
	assert(mSBuf.isLoaded());
	return mSBuf.getSoundBuffer();
}
