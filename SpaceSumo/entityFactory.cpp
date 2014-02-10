#include "stdafx.h"
#include "entityFactory.h"
#include "SpaceManImp.h"
#include <Common\Config.h>
#include <Common\stringH.h>
#include "LHydrogen.h"

EntityImp* entFac::createSpaceMan(std::string conf, b2World& world,
								  std::string bodyData, float x, float y)
{
	Config config("res/conf/spaceman.cfg");
	Config controls(conf);
		
	return new SpaceManImp(
		str::toKey(controls.getValue<std::string>("up")), 
		str::toKey(controls.getValue<std::string>("right")), 
		str::toKey(controls.getValue<std::string>("left")), 
		str::toKey(controls.getValue<std::string>("push")),
		world, bodyData, x, y);
}

EntityImp* entFac::createPowerUpLHydrogen(b2World& world)
{
	std::string bodyData("res/conf/powerUpBody.cfg");
	return new LHydrogen(world, bodyData);
}

EntityImp* entFac::createPowerUpRandom(std::string conf, b2World& world)
{
	return new LHydrogen(world, conf);
}