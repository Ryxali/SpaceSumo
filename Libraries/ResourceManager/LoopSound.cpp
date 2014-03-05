#include "LoopSound.h"


LoopSound::LoopSound(Playable* sound) :
	mIsPlaying(false),
	mDestroy(false),
	mSound(sound)
{

}


LoopSound::~LoopSound()
{
	delete mSound;
}

bool LoopSound::isPlaying()
{
	return mIsPlaying;
}

bool LoopSound::hasEnded()
{
	return !mIsPlaying || mSound->hasEnded();
}

void LoopSound::play()
{
	mIsPlaying = true;
	mSound->play();
}

void LoopSound::stop()
{
	mIsPlaying = false;
	mSound->stop();
}

void LoopSound::forceStop()
{
	stop();
}

void LoopSound::setDestroy(bool status)
{
	mDestroy = status;
}

bool LoopSound::getDestroy()
{
	return mDestroy;
}

void LoopSound::update(GameData& gData)
{
	if(mSound->hasEnded() && mIsPlaying)
	{
		mSound->play();
	}
}

void LoopSound::setRelativeToListener(bool status)
{
	mSound->setRelativeToListener(status);
}
void LoopSound::setPosition(float x, float y, float z)
{
	mSound->setPosition(x, y, z);
}