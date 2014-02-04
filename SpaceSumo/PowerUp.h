#pragma once
#include "entityimp.h"
class PowerUp :
	public EntityImp
{
public:
	~PowerUp();

	virtual void update() = 0;
	virtual void draw() = 0;
};

