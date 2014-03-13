#include "FinishingSound.h"


FinishingSound::FinishingSound(Playable* sound) : mSound(sound), mStopping(false)
{
}


FinishingSound::~FinishingSound(void)
{
	delete mSound;
}
bool FinishingSound::isPlaying()
{
	return mSound->isPlaying();
}
bool FinishingSound::hasEnded()
{
	return mSound->hasEnded();
}
void FinishingSound::play()
{
	mStopping = false;
	mSound->play();
}
void FinishingSound::stop()
{
	mStopping = true;
}
void FinishingSound::forceStop()
{
	mSound->forceStop();
}
void FinishingSound::setDestroy(bool val)
{
	mSound->setDestroy(val);
}
bool FinishingSound::getDestroy()
{
	return mSound->getDestroy();
}
void FinishingSound::update()
{
	mSound->update();
}

void FinishingSound::setRelativeToListener(bool status)
{
	mSound->setRelativeToListener(status);
}

void FinishingSound::setAttenuation(float atten)
{
	mSound->setAttenuation(atten);
}

void FinishingSound::setPosition(float x, float y, float z = 0)
{
	mSound->setPosition(x, y, z);
}