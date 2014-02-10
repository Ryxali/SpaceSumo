#pragma once
#include <string>
#include <Box2D\Box2D.h>

class EntityImp;

namespace entFac
{
	EntityImp* createSpaceMan(std::string conf, b2World& world,
		std::string bodyData, float x, float y);

	EntityImp* createPowerUpLHydrogen(b2World& world);

	EntityImp* createPowerUpRandom(std::string conf, b2World& world);


};