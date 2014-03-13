#pragma once

struct GameData;
struct SpacemanData;
class EntityImp;

#include <string>
#include <Box2D\Box2D.h>
#include <Common\SVector.h>
#include <Common\Config.h>


namespace entFac
{
	EntityImp* createSpaceMan(std::string keyConf, GameData& data,
		std::string bodyData, std::string handData,
		float x, float y, float32 rotation);
	EntityImp* createSpaceMan(SpacemanData& sData, GameData& gData, int playerIndex, SVector pos, float startRotation);

	EntityImp* createPowerUpLHydrogen(b2World& world, float x, float y);

	EntityImp* createPowerUpEnergyTorpedo(b2World& world, float x, float y);

	EntityImp* createPowerUpEMP(b2World& world, float x, float y);

	EntityImp* createPowerUpRandom(b2World& world, float x, float y);
};