#pragma once
class Playable;
#include "map.h"
#include <ResourceManager\SSprite.h>
#include <SFML\Audio\Music.hpp>
#include <Common\Timer.h>
#include <Common\Config.h>

class MiningColony :
	public Map
{
public:
	MiningColony();

	virtual void update(GameStateData &data, int delta);
	virtual void draw(RenderList &list);
	virtual void init(GameData &data);
	virtual void close();

private:
	SSprite mBackground;
	Playable* mSoundtrack;

	Timer mAsteroidTimer;
};

