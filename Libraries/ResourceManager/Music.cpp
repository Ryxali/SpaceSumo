#include "Music.h"
#include <Common\Config.h>

static Config CFG("res/conf/main.cfg");

Music::Music(std::string ref) : mMusic(), mDestroy(false)
{
	mMusic.openFromFile(ref);
	mMusic.setVolume(CFG.getValue<int>("music_volume"));
}


Music::~Music()
{
}

bool Music::isPlaying()
{
	return mMusic.getStatus() == sf::Music::Playing;
}

bool Music::hasEnded()
{
	return mMusic.getStatus() == sf::Music::Stopped;
}

void Music::play()
{
	mMusic.play();
}

void Music::stop()
{
	mMusic.stop();
}

void Music::forceStop()
{
	mMusic.stop();
}

void Music::setDestroy(bool status)
{
	mDestroy = status;
}

bool Music::getDestroy()
{
	return mDestroy;
}

void Music::update()
{

}


void Music::setRelativeToListener(bool status)
{
	mMusic.setRelativeToListener(status);
}

void Music::setAttenuation(float val)
{
	mMusic.setAttenuation(val);
}

void Music::setPosition(float x, float y, float z)
{
	mMusic.setPosition(x, y, z);
}