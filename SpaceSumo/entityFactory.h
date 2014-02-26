#pragma once
#include <string>
#include <Box2D\Box2D.h>

class EntityImp;

namespace entFac
{
	EntityImp* createSpaceMan(std::string keyConf, b2World& world,
		std::string bodyData, std::string handData,
		float x, float y, float32 rotation);
	EntityImp* createSpaceMan(std::string playerConf, std::string bodyConf, std::string handConf, b2World& world);

	EntityImp* createPowerUpLHydrogen(b2World& world, float x, float y);

	EntityImp* createPowerUpRandom(std::string conf, b2World& world, float x, float y);
};