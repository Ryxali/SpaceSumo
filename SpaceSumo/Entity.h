#pragma once
#include <memory>
#include "Effect.h"

enum EntityType;
struct GameStateData;
class EntityImp;
class RenderList;
struct GameData;

class Entity
{
public:
	Entity(EntityImp* entity);
	Entity(const Entity& ent);
	~Entity();
	void update(GameData &data, GameStateData &gData,int delta);
	void draw(RenderList& renderList);
	bool isAlive();
	EntityType getType();

private:
	std::shared_ptr<EntityImp> mEntity;
	Entity& operator=(const Entity& ent);
	//EntityImp* mEntity;
};

