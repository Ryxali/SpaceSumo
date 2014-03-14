#pragma once
#include "map.h"
#include <ResourceManager\SSprite.h>
#include <SFML\Audio\Music.hpp>
#include <ResourceManager\Animation.h>
class Terra :
	public Map
{
public:
	Terra();
	virtual void update(GameStateData &data, int delta);
	virtual void draw(RenderList &list);
	virtual void init(GameData &data);
	virtual void close();

private:
	SSprite mBackground;
	sf::Music mSoundtrack;
};

