#pragma once
#include "Mode.h"
#include <ResourceManager\SSprite.h>
#include "Zone.h"
class Sumo : public Mode
{
public:
	Sumo(b2World& world);
	~Sumo();
	virtual void update(GameData &data, GameStateData &gData, int delta);
	virtual void draw(RenderList &list);
	virtual void init(GameData &data);
private:
	SSprite mTest;
	Zone mZone;
};

