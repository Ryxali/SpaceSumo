#pragma once
#include "powerup.h"
#include "entityFactory.h"
#include <Box2D\Box2D.h>
#include "B2Body.h"
#include <Common\Config.h>
#include "Freezer.h"

class LHydrogen :
	public PowerUp
{
public:
	LHydrogen(b2World world, std::string bodyData);
	~LHydrogen();

	virtual void update(GameData &data, int delta);
	virtual void draw(RenderList& renderList);
	Ability* getAbility();

private:
	bool mPickedUp;
	B2Body mBody;
};
