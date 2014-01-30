#pragma once
#include "entity.h"

class EffectEntity :
	public Entity
{
public:

	virtual ~EffectEntity();

	virtual void update() = 0;
	virtual void movement() = 0;
	virtual void draw() = 0;

	virtual Type getType();

	void initiate(Entity ** e);

	Entity* mParent;
	Entity* mChild;

protected:
	Entity ** mRoot;
	
};

