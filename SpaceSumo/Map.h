#pragma once
#include "Map_Type.h"
struct GameData;
class RenderList;
class Map
{
public:
	virtual ~Map() {}
	virtual void update(GameData &data) = 0;
	virtual void draw(RenderList &list) = 0;
	virtual void init(GameData &data) = 0;
private:
	Map_Type mType;
};

