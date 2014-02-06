#include "stdafx.h"
#include "entityFactory.h"
#include <Common\Config.h>
#include "SpaceManImp.h"
#include <Common\stringH.h>

EntityImp* entFac::createSpaceMan(std::string conf, b2World& world)
{
	Config config("res/conf/spaceman.cfg");
	Config controls(conf);
		
	return new SpaceManImp(
		str::toKey(controls.getValue<std::string>("up")), 
		str::toKey(controls.getValue<std::string>("right")), 
		str::toKey(controls.getValue<std::string>("left")), 
		str::toKey(controls.getValue<std::string>("push")),
		world, 300.0f, 300.0f);;
}