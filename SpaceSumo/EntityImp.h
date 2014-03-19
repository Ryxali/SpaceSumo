#pragma once

namespace enttype
{
	enum EntityType;
}
struct GameStateData;


#include "Collideable.h"
#include "RenderList.h"
#include "GameData.h"


class EntityImp : public Collideable
{
public:
	EntityImp() {}
	virtual ~EntityImp() {}

	virtual void update(GameData &data, GameStateData &gData, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual bool isAlive() = 0;
	virtual void onCollide(Collideable* other) = 0;
	virtual void onLeave(Collideable* other) = 0;
	virtual enttype::EntityType getType() = 0;
	virtual void clean(GameData& data);
private:
	EntityImp(const EntityImp& eImp);
	EntityImp& operator=(const EntityImp& eImp);
};

