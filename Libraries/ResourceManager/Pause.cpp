#include "Pause.h"


Pause::Pause(int duration) : mTimer(), mEnd(duration), mPlaying(false), mDestroy(false)
{
}


Pause::~Pause()
{
}

bool Pause::isPlaying()
{
	return mPlaying;
}

bool Pause::hasEnded()
{
	return !isPlaying();
}

void Pause::play()
{
	mTimer.restart();
	mPlaying = true;
}

void Pause::stop()
{
	mPlaying = false;
}

void Pause::forceStop()
{
	mPlaying = false;
}

void Pause::setDestroy(bool status)
{
	mDestroy = status;
}

bool Pause::getDestroy()
{
	return mDestroy;
}

void Pause::update()
{
	if(mPlaying && mTimer.getElapsedTime().asMilliseconds() > mEnd)
		mPlaying = false;
}


void Pause::setRelativeToListener(bool status)
{

}

void Pause::setAttenuation(float status)
{

}
void Pause::setPosition(float x, float y, float z)
{

}