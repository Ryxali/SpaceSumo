#include "stdafx.h"
#include "entityFactory.h"
#include "SpaceManImp.h"
#include <Common\Config.h>
#include "LHydrogen.h"
#include <Common\stringH.h>
#include "ETorpedoPickup.h"
#include <cstdlib>
#include "EMP.h"
#include <Common\error.h>

#include "GameData.h"
#include "SpacemanData.h"

static Config spawnRates("res/conf/powerup/spawnRates.cfg");

EntityImp* entFac::createSpaceMan(
	std::string conf, GameData& data,
	std::string bodyData, std::string handData,
	float x, float y, float32 rotation)
{
	Config config("res/conf/spaceman.cfg");
	Config controls(conf);
		
	return 0;/*new SpaceManImp(
		str::toKey(controls.getValue<std::string>("up")), 
		str::toKey(controls.getValue<std::string>("right")), 
		str::toKey(controls.getValue<std::string>("left")), 
		str::toKey(controls.getValue<std::string>("push")),
		str::toKey(controls.getValue<std::string>("activate")),
		data, bodyData, handData,  x, y, rotation);*/
}

EntityImp* entFac::createSpaceMan(SpacemanData& sData, GameData& gData, Head& head, int playerIndex, SVector pos, float startRotation)
{
	
	/*return new SpaceManImp(
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
		);*/
		
		
	return new SpaceManImp(
		gData.controlList.get(playerIndex),
		pos, startRotation,
		Config("res/conf/characters/spaceman/visual_data_"+std::to_string(playerIndex+1)+".cfg"),
		Config(sData.bodyData),
		Config(sData.handData),
		gData,
		head,
		sData.headRef);

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

EntityImp* createPowerUpEMP(b2World& world, float x, float y)
{
	std::string bodyData("res/conf/powerUpBody.cfg");
	return new EMP(world, bodyData, x, y);
}

EntityImp* entFac::createPowerUpRandom(b2World& world, float x, float y)
{
	std::string bodyData("res/conf/powerUpBody.cfg");
	int totalChance = spawnRates.getValue<int>("LHydrogen") +
		spawnRates.getValue<int>("EnergyTorpedo") + 
		spawnRates.getValue<int>("EMP");
	int previous = 0;
	int rand_val = rand() % totalChance;
	
	if(rand_val < spawnRates.getValue<int>("LHydrogen"))
	{
		return new LHydrogen(world, bodyData, x, y);
	}
	else
		previous += spawnRates.getValue<int>("LHydrogen");
		
	if(rand_val < previous + spawnRates.getValue<int>("EnergyTorpedo"))
	{
		return new ETorpedoPickup(world, bodyData, x, y);
	}
	else
		previous += spawnRates.getValue<int>("EnergyTorpedo");

	if(rand_val < previous + spawnRates.getValue<int>("EMP"))
	{
		return new EMP(world, bodyData, x, y);
	}
	else 
		previous += spawnRates.getValue<int>("EMP");

	SError("Random value out of bounds", "The Randomization value for powerup spawn is not in the desired range" + rand_val);
	return 0;
}