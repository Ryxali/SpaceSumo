#pragma once
#include "Playable.h"
#include <vector>
#include "SSound.h"
#include <list>
class SoundQuene : public  Playable
{
public:
	SoundQuene();
	~SoundQuene();
	virtual bool isPlaying();
	virtual bool hasEnded();
	virtual void play();
	virtual void stop();
	virtual void forceStop();
	virtual void setDestroy(bool status);
	virtual bool getDestroy();
	virtual void update();
	
	void add(Playable* sound);

	virtual void setRelativeToListener(bool);
	virtual void setAttenuation(float);
	virtual void setPosition(float x, float y, float z);

private:
	std::list<Playable*> mSounds;
	std::list<Playable*>::iterator mCurrentSound;

	bool mIsPlaying, mHasEnded, mDestroy, mStopping;
};

