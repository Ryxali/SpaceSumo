#include "stdafx.h"
#include "entityFactory.h"
#include "SpaceManImp.h"
#include <Common\Config.h>
#include "LHydrogen.h"
#include <Common\stringH.h>
#include "ETorpedoPickup.h"
#include <cstdlib>

EntityImp* entFac::createSpaceMan(
	std::string conf, GameData& data,
	std::string bodyData, std::string handData,
	float x, float y, float32 rotation)
{
	Config config("res/conf/spaceman.cfg");
	Config controls(conf);
		
	return new SpaceManImp(
		str::toKey(controls.getValue<std::string>("up")), 
		str::toKey(controls.getValue<std::string>("right")), 
		str::toKey(controls.getValue<std::string>("left")), 
		str::toKey(controls.getValue<std::string>("push")),
		str::toKey(controls.getValue<std::string>("activate")),
		data, bodyData, handData,  x, y, rotation);
}

EntityImp* entFac::createSpaceMan(std::string playerConf, std::string bodyConf, std::string handConf, GameData& data)
{
	Config pConf(playerConf);
	
	return new SpaceManImp(
		str::toKey(pConf.getValue<std::string>("up")), 
		str::toKey(pConf.getValue<std::string>("right")), 
		str::toKey(pConf.getValue<std::string>("left")), 
		str::toKey(pConf.getValue<std::string>("push")),
		str::toKey(pConf.getValue<std::string>("activate")),
		data,
		bodyConf,
		handConf,
		pConf.getValue<int>("startingX"),
		pConf.getValue<int>("startingY"),
		pConf.getValue<float>("startingRotation")
		);
}

EntityImp* entFac::createPowerUpLHydrogen(b2World& world, float x, float y)
{
	std::string bodyData("res/conf/powerUpBody.cfg");
	return new LHydrogen(world, bodyData, x, y);
}

EntityImp* entFac::createPowerUpEnergyTorpedo(b2World& world, float x, float y)
{
	std::string bodyData("res/conf/powerUpBody.cfg");
	return new ETorpedoPickup(world, bodyData, x, y);
}


EntityImp* entFac::createPowerUpRandom(b2World& world, float x, float y)
{
	std::string bodyData("res/conf/powerUpBody.cfg");
	int rand_val = rand() % 2;
	switch ( rand_val )
	{
	case 0:
		return new LHydrogen(world, bodyData, x, y);
	break;
		
	case 1:
		return new ETorpedoPickup(world, bodyData, x, y);
	break;

	default:

	break;
	}
}