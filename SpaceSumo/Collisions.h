#pragma once
#include "SpaceMan.h"

class Collisions
{
public:
	Collisions(SpaceMan &spaceMan1, SpaceMan &spaceMan2);
	~Collisions();
	void testPlayerCollisions();

private:
	SpaceMan &mSpaceMan1;
	SpaceMan &mSpaceMan2;
};

