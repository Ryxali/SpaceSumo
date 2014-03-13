#pragma once
#include "map.h"
#include <ResourceManager\SSprite.h>
#include <SFML\Audio\Music.hpp>
#include <Common\Timer.h>

class MiningColony :
	public Map
{
public:
	MiningColony();

	virtual void update(GameData &data);
	virtual void draw(RenderList &list);
	virtual void init(GameData &data);
	virtual void close();

private:
	SSprite mBackground;
	sf::Music mSoundtrack;

	Timer mAsteroidTimer;
};

