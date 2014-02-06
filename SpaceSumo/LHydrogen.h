#pragma once
#include "powerup.h"
#include "entityFactory.h"
#include <Box2D\Box2D.h>

class LHydrogen :
	public PowerUp
{
public:
	LHydrogen();
	~LHydrogen();

	virtual void update(int delta);
	virtual void draw(RenderList& renderList);
};

