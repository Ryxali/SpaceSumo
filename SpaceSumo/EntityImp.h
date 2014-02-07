#pragma once
#include "RenderList.h"
#include "GameData.h"
class EntityImp
{
public:
	virtual ~EntityImp() {}

	virtual void update(GameData &data, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	// TODO add Effect to param
	virtual void addEffect() = 0;
};

