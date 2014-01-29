#pragma once
#include "entity.h"

class GeneralEntity :
	public Entity
{
public:
	virtual ~GeneralEntity() {}

	virtual void update() = 0;
	virtual void movement() = 0;
	virtual void draw() = 0;

	virtual Type getType();

protected:
	// position and box2D magic
};

