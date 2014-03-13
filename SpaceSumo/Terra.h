#pragma once
#include "map.h"
#include <ResourceManager\SSprite.h>
#include <SFML\Audio\Music.hpp>
class Terra :
	public Map
{
public:
	Terra();
	virtual void update(GameData &data);
	virtual void draw(RenderList &list);
	virtual void init(GameData &data);
	virtual void close();

private:
	SSprite mBackground;
	sf::Music mSoundtrack;

};

