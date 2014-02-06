#pragma once
#include "EntityImp.h"
#include <string>
#include <Box2D\Box2D.h>

namespace entFac
{
	EntityImp* createSpaceMan(std::string conf, b2World& world);

	EntityImp* createPowerUpLHydrogen(b2World& world);

	EntityImp* createPowerUpRandom(std::string conf, b2World& world);


};