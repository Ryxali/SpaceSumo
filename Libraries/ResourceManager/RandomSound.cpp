#include "RandomSound.h"
#include <random>

RandomSound::RandomSound() : 
	mSounds(),
	mCurrentSound(0),
	mDestroy(false)
{
}


RandomSound::~RandomSound()
{
}

bool RandomSound::isPlaying()
{
	if(mCurrentSound == 0)
		return false;
	return mCurrentSound->isPlaying();
}

bool RandomSound::hasEnded()
{
	if(mCurrentSound == 0)
		return true;
	return mCurrentSound->hasEnded();
}

void RandomSound::play()
{
	stop();
	mCurrentSound = mSounds[std::rand()%mSounds.size()];
	mCurrentSound->play();
}

void RandomSound::stop()
{
	if(mCurrentSound != 0)
		mCurrentSound->stop();
}

void RandomSound::forceStop()
{
	if(mCurrentSound != 0)
		mCurrentSound->stop();
}

void RandomSound::setDestroy(bool status)
{
	mDestroy = status;
}

bool RandomSound::getDestroy()
{
	return mDestroy;
}

void RandomSound::update()
{
	if(mCurrentSound != 0)
		mCurrentSound->update();
}
	
void RandomSound::add(Playable* sound)
{
	mSounds.push_back(sound);
}

void RandomSound::setRelativeToListener(bool status)
{
	for(auto it = mSounds.begin(); it != mSounds.end(); ++it)
	{
		(*it)->setRelativeToListener(status);
	}
}

void RandomSound::setAttenuation(float att)
{
	for(auto it = mSounds.begin(); it != mSounds.end(); ++it)
	{
		(*it)->setAttenuation(att);
	}
}

void RandomSound::setPosition(float x, float y, float z)
{
	for(auto it = mSounds.begin(); it != mSounds.end(); ++it)
	{
		(*it)->setPosition(x, y, z);
	}
}