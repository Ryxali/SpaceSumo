#pragma once
#include "powerup.h"
#include "entityFactory.h"
#include <Box2D\Box2D.h>
#include "B2Body.h"
#include <Common\Config.h>
#include "Ability.h"

class LHydrogen :
	public PowerUp
{
public:
	LHydrogen(b2World world, std::string bodyData);
	~LHydrogen();

	virtual void update(int delta);
	virtual void draw(RenderList& renderList);
	void activate();

private:
	B2Body mBody;
};

