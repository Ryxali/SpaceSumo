#include "stdafx.h"
#include "Sumo.h"
#include <ResourceManager\RHandle.h>
#include "RenderList.h"
#include "GameData.h"
Sumo::Sumo(void) : Mode(), mTest(res::getTexture("res/img/Map_Barrier/Laser_Long.png"), 0.f), mZone()
{
	addSupportedMapType(Map_Type::TERRA);
	addSupportedMapType(Map_Type::MINING_COLONY);
}


Sumo::~Sumo(void)
{
}

void Sumo::update(GameData &data, GameStateData &gData, int delta)
{
	mZone.update(data, gData, delta);
}

void Sumo::draw(RenderList &list)
{
	//list.addSprite(mTest);
	mZone.draw(list);
}

void Sumo::init(GameData &data)
{
	res::loadResource("res/img/Map_Barrier/Laser_Long.png");
}