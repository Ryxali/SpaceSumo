#include "LoopSound.h"


LoopSound::LoopSound(const SSoundBuffer& buffer):
	mIsPlaying(false),
	mDestroy(false),
	mSound(buffer)
{
	mSound.getSound().setLoop(true);
}


LoopSound::~LoopSound()
{
}

bool LoopSound::isPlaying()
{
	return mIsPlaying;
}

bool LoopSound::hasEnded()
{
	return mSound.hasEnded() || mIsPlaying;
}

void LoopSound::play()
{
	mIsPlaying = true;
	mSound.play();
}

void LoopSound::stop()
{
	mIsPlaying = false;
	mSound.stop();
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

}
