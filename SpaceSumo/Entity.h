#pragma once
#include "EntityImp.h"
#include <memory>
#include "GameData.h"

class Entity
{
public:
	Entity(EntityImp* entity);
	Entity(const Entity& ent);
	~Entity();
	void update(GameData &data, int delta);
	void draw(RenderList& renderList);
	bool addEffect();

private:
	std::shared_ptr<EntityImp> mEntity;
	Entity& operator=(const Entity& ent);
	//EntityImp* mEntity;
};

