#pragma once
#include <ResourceManager\Playable.h>
#include <ResourceManager\SSound.h>

class LoopSound : public Playable
{
public:
	LoopSound(const SSoundBuffer& buffer);
	~LoopSound();

	virtual bool isPlaying();
	virtual bool hasEnded();
	virtual void play();
	virtual void stop();
	virtual void setDestroy(bool);
	virtual bool getDestroy();
	virtual void update(GameData&);

private:
	bool mIsPlaying;
	bool mDestroy;
	SSound mSound;
};

