#pragma once
#include <Common\SVector.h>
#include "Entity.h"

class Ability
{
public:
	~Ability();

	virtual void activate(SVector pos, SVector dir, Entity& target) = 0;
};

