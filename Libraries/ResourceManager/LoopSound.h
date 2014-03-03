#pragma once
#include <ResourceManager\Playable.h>

class LoopSound : public Playable
{
public:
	LoopSound(Playable* sound);
	~LoopSound();

	virtual bool isPlaying();
	virtual bool hasEnded();
	virtual void play();
	virtual void stop();
	virtual void forceStop();
	virtual void setDestroy(bool);
	virtual bool getDestroy();
	virtual void update(GameData&);

private:
	bool mIsPlaying;
	bool mDestroy;
	Playable* mSound;
};

