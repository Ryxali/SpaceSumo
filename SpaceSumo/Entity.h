#pragma once
#include "EntityImp.h"
class Entity
{
public:
	Entity(EntityImp* entity);
	~Entity();
	void update();
	void draw();
	bool addEffect();

private:
	EntityImp* mEntity;
};

