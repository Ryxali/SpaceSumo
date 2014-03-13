#pragma once
#include "Playable.h"

class FinishingSound : public Playable
{
public:
	FinishingSound(Playable* sound);
	~FinishingSound();
	virtual bool isPlaying();
	virtual bool hasEnded();
	virtual void play();
	virtual void stop();
	virtual void forceStop();
	virtual void setDestroy(bool);
	virtual bool getDestroy();
	virtual void update(GameData&);

	virtual void setRelativeToListener(bool);
	virtual void setAttenuation(float);
	virtual void setPosition(float x, float y, float z);
private:
	Playable* mSound;
	bool mStopping;

};

