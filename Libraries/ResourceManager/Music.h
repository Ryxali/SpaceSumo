#pragma once
#include "Playable.h"
#include <string>
#include <SFML\Audio\Music.hpp>
class Music : public Playable
{
public:
	Music(std::string);
	~Music();

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
	sf::Music mMusic;
	bool mDestroy;
};

