#pragma once
#include "Playable.h"
#include <SFML\System\Clock.hpp>

class Pause : public Playable
{
public:
	Pause(int duration);
	~Pause();

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
	virtual void setPosition(float x, float y, float z = 0);
private:
	sf::Clock mTimer;
	int mEnd;
	bool mPlaying;
	bool mDestroy;
};

