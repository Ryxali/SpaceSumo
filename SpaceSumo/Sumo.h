#pragma once
#include "Mode.h"
#include <ResourceManager\SSprite.h>
class Sumo : public Mode
{
public:
	Sumo();
	~Sumo();
	virtual void update(GameData &data);
	virtual void draw(RenderList &list);
	virtual void init(GameData &data);
private:
	SSprite mTest;
};

