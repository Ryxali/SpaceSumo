#pragma once
#include "EntityImp.h"


class Entity
{
public:
	Entity(EntityImp* entityImp);
	~Entity();
	virtual void draw();
	virtual void update();
	virtual bool addEffect();

private:
	
	EntityImp* mEntity;
};

