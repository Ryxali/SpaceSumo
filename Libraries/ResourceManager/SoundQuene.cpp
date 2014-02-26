#include "SoundQuene.h"


SoundQuene::SoundQuene():
	mDestroy(false),
	atEnd(false),
	mCurrentSound(0)
{

}


SoundQuene::~SoundQuene()
{

}

bool SoundQuene::isPlaying()
{
	if( mSounds[mCurrentSound]->isPlaying() )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SoundQuene::hasEnded()
{
	if( atEnd )
	{
		return true;
	}
	else
	{
		return false;
	}

}

void SoundQuene::play()
{
	mSounds[mCurrentSound]->play();
}

void SoundQuene::stop()
{
	mSounds[mCurrentSound]->stop();
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
	if( mSounds[mCurrentSound]->hasEnded() )
	{
		if( mCurrentSound == mSounds.size() )
		{
			mCurrentSound++;
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
}

int SoundQuene::getCurrentIndex()
{
	return mCurrentSound;
}

void SoundQuene::setCurrentIndex(int index)
{
	mCurrentSound = index;
}
