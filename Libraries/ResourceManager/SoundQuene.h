#pragma once
#include "Playable.h"
#include <vector>
#include "SSound.h"
class SoundQuene : public  Playable
{
public:
	SoundQuene();
	~SoundQuene();
	virtual bool isPlaying();
	virtual bool hasEnded();
	virtual void play();
	virtual void stop();
	virtual void setDestroy(bool status);
	virtual bool getDestroy();
	virtual void update(GameData& gData);
	
	void add(Playable* sound);
	int getCurrentIndex();
	void setCurrentIndex(int index);

private:
	std::vector<Playable*> mSounds;
	bool mDestroy;
	bool atEnd;
	int mCurrentSound;
};

