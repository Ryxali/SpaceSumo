#include "SoundQuene.h"
#include <iostream>

SoundQuene::SoundQuene():
	mSounds(),
	mCurrentSound(mSounds.begin()),
	mDestroy(false),
	mHasEnded(true),
	mIsPlaying(false),
	mStopping(false)
{
	
}


SoundQuene::~SoundQuene()
{
	// TODO
}

bool SoundQuene::isPlaying()
{
	return mIsPlaying;
}

bool SoundQuene::hasEnded()
{
	return mHasEnded;
}

void SoundQuene::play()
{
	mCurrentSound = mSounds.begin();
	(*mCurrentSound)->play();
	mHasEnded = false;
	mStopping = false;
	mIsPlaying = true;
}

void SoundQuene::stop()
{
	mStopping = true;
	if(mCurrentSound != mSounds.end())
		(*mCurrentSound)->stop();
}
void SoundQuene::forceStop()
{
	(*mCurrentSound)->forceStop();
	mHasEnded = true;
}
void SoundQuene::setDestroy(bool status)
{
	mDestroy = status;
}

bool SoundQuene::getDestroy()
{
	return mDestroy;
}

void SoundQuene::update(GameData& gData)
{
	if(!hasEnded())
	{
		(*mCurrentSound)->update(gData);
		if(mStopping)
			(*mCurrentSound)->stop();

		if((*mCurrentSound)->hasEnded())
		{
			++mCurrentSound;
			if(mCurrentSound == mSounds.end())
			{
				mHasEnded = true;
			}
			else
			{
				(*mCurrentSound)->play();
				if(mStopping)
					(*mCurrentSound)->stop();
			}

		}
	}
}

void SoundQuene::add(Playable* sound)
{
	mSounds.push_back(sound);
	mCurrentSound = mSounds.begin();
}

void SoundQuene::setRelativeToListener(bool)
{
	for(auto it = mSounds.begin(); it != mSounds.end(); ++it)
	{
		(*it)->setRelativeToListener(true);
	}
}

void SoundQuene::setPosition(float x, float y, float z = 0)
{
	for(auto it = mSounds.begin(); it != mSounds.end(); ++it)
	{
		(*it)->setPosition(x, y, z);
	}
}