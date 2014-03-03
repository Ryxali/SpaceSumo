#include "SoundQuene.h"
#include <iostream>

SoundQuene::SoundQuene():
	mSounds(),
	mDestroy(false),
	atEnd(true),
	mCurrentSound(mSounds.begin())
{
	
}


SoundQuene::~SoundQuene()
{
	// TODO
}

bool SoundQuene::isPlaying()
{
	return (*mCurrentSound)->isPlaying();
}

bool SoundQuene::hasEnded()
{
	return atEnd;
}

void SoundQuene::play()
{
	if( hasEnded() && !isPlaying())
	{
		mCurrentSound = mSounds.begin();
		(*mCurrentSound)->play();
		atEnd = false;
	}
}

void SoundQuene::stop()
{
	atEnd = true;
	(*mCurrentSound)->stop();
	mCurrentSound = mSounds.begin();
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
	if( !hasEnded() )
	{
		if( mCurrentSound != mSounds.end() )
		{
			mCurrentSound++;
			
			if( mCurrentSound == mSounds.end() )
			{
				mCurrentSound = mSounds.begin();
				atEnd = true;
			}
			else
			{
				(*mCurrentSound)->play();
			}
		}
		else
		{
			atEnd = true;
		}
	}
}

void SoundQuene::add(Playable* sound)
{
	mSounds.push_back(sound);
	mCurrentSound = mSounds.begin();
}