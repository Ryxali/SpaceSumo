#pragma once
#include <Common\SVector.h>

class Ability
{
public:
	~Ability();

	virtual void activate(SVector pos, SVector dir) = 0;
};

