#pragma once
#include <string>
#include <Box2D\Box2D.h>
#include "GameData.h"

class EntityImp;

namespace entFac
{
	EntityImp* createSpaceMan(std::string keyConf, GameData& data,
		std::string bodyData, std::string handData,
		float x, float y, float32 rotation);
	EntityImp* createSpaceMan(std::string playerConf, std::string bodyConf, std::string handConf, GameData& data);

	EntityImp* createPowerUpLHydrogen(b2World& world, float x, float y);

	EntityImp* createPowerUpEnergyTorpedo(b2World& world, float x, float y);

	EntityImp* createPowerUpRandom(b2World& world, float x, float y);
};