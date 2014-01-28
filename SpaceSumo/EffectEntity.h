#pragma once
#include "entity.h"
class EffectEntity :
	public Entity
{
public:
	virtual ~EffectEntity() {}

	virtual void update() = 0;
	virtual void movement() = 0;
	virtual void draw() = 0;

	// get & set
	virtual bool getIsAffected() = 0;
	virtual void setIsAffected(bool) = 0;
	
	virtual Entity* getEffect() = 0;
	virtual void setEffect(Entity* effect) = 0;

	Entity* getTarget();
	void setTarget(Entity* target);

protected:
	Entity* target;
};

