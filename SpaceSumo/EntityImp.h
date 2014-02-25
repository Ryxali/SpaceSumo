#pragma once
#include "RenderList.h"
#include "GameData.h"

enum EntityType;
struct GameStateData;

class EntityImp
{
public:
	EntityImp() {}
	virtual ~EntityImp() {}

	virtual void update(GameData &data, GameStateData &gData, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual bool isAlive() = 0;
	virtual EntityType getType() = 0;
	virtual void clean(GameData& data);
private:
	EntityImp(const EntityImp& eImp);
	EntityImp& operator=(const EntityImp& eImp);
};

