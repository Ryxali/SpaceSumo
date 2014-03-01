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
private:
	Playable* mSound;
	bool mStopping;

};

