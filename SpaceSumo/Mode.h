#pragma once
#include "Map_Type.h"
struct GameData;
class RenderList;
class Mode
{
public:
	virtual ~Mode(){}
	virtual void update(GameData &data) = 0;
	virtual void draw(RenderList &list) = 0;
	virtual void init(GameData &data) = 0;
private:
	const Map_Type* mAllowedTypes;
};