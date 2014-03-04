#include "UnyieldingSound.h"


UnyieldingSound::UnyieldingSound(Playable* sound) : mSound(sound)
{

}
UnyieldingSound::~UnyieldingSound()
{
	delete mSound;
}
bool UnyieldingSound::isPlaying()
{
	return mSound->isPlaying();
}
bool UnyieldingSound::hasEnded()
{
	return mSound->hasEnded();
}
void UnyieldingSound::play()
{
	if(!mSound->isPlaying())
		mSound->play();
}
void UnyieldingSound::stop()
{
	mSound->stop();
}
void UnyieldingSound::forceStop()
{
	mSound->forceStop();
}
void UnyieldingSound::setDestroy(bool status)
{
	mSound->setDestroy(status);
}
bool UnyieldingSound::getDestroy()
{
	return mSound->getDestroy();
}
void UnyieldingSound::update(GameData& data)
{
	mSound->update(data);
}

void UnyieldingSound::setRelativeToListener(bool status)
{
	mSound->setRelativeToListener(status);
}
void UnyieldingSound::setPosition(float x, float y, float z)
{
	mSound->setPosition(x, y, z);
}