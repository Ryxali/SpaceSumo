#pragma once
#include <string>
#include <Box2D\Box2D.h>
#include "GameData.h"

class EntityImp;

namespace entFac
{
	EntityImp* createSpaceMan(std::string conf, b2World& world,
		GameData& data, std::string bodyData, std::string handData,
		float x, float y, float32 rotation);

	EntityImp* createPowerUpLHydrogen(b2World& world, float x, float y);

	EntityImp* createPowerUpRandom(std::string conf, b2World& world, float x, float y);
};