#pragma once
#include "Playable.h"
#include <vector>

class RandomSound : public Playable
{
public:
	RandomSound();
	~RandomSound();

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
	std::vector<Playable*> mSounds;
	Playable* mCurrentSound;

	bool mDestroy;
};

