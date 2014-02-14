#include "SequentialSound.h"


SequentialSound::SequentialSound(bool autoLoop, bool repeat) : mSounds(), mCurSound(0), mAutoLoop(autoLoop), mRepeat(repeat), mIsPlaying(false)
{
}

SequentialSound::~SequentialSound()
{
}

void SequentialSound::add(SSoundBuffer &sSBuf)
{
	mSounds.emplace_back(sSBuf);
}

void SequentialSound::start()
{
	if(!mIsPlaying)
	{
		mIsPlaying = true;
		mSounds[mCurSound].play();
	}
}

void SequentialSound::stop()
{
	if(mIsPlaying)
	{
		mIsPlaying = false;
		mSounds[mCurSound].stop();
	}
}

void SequentialSound::reset()
{

}