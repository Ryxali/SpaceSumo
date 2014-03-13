#pragma once
#include "Playable.h"

class UnyieldingSound : public Playable
{
public:
	UnyieldingSound(Playable*);
	~UnyieldingSound();

	virtual bool isPlaying();
	virtual bool hasEnded();
	virtual void play();
	virtual void stop();
	virtual void forceStop();
	virtual void setDestroy(bool);
	virtual bool getDestroy();
	virtual void update();

	virtual void setRelativeToListener(bool);
	virtual void setAttenuation(float);
	virtual void setPosition(float x, float y, float z);
private:
	Playable* mSound;
};