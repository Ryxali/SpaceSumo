#pragma once
#include "Ability.h"
#include <Common\Config.h>

class Freezer :
	public Ability
{
public:
	Freezer();
	~Freezer();

	virtual void activate(SVector pos, SVector dir);

private:
	static Config mConfig;
	int mIntensity;
	int mSpeed;
};
