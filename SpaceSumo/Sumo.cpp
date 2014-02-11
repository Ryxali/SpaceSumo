#include "stdafx.h"
#include "Sumo.h"
#include <ResourceManager\RHandle.h>
#include "RenderList.h"
Sumo::Sumo(void) : Mode(), mTest(res::getTexture("res/img/Map_Barrier/Laser_Long.png"), 0.f)
{
	addSupportedMapType(Map_Type::TERRA);
	addSupportedMapType(Map_Type::MINING_COLONY);
}


Sumo::~Sumo(void)
{
}

void Sumo::update(GameData &data)
{

}

void Sumo::draw(RenderList &list)
{
	list.addSprite(mTest);
}

void Sumo::init(GameData &data)
{
	res::loadResource("res/img/Map_Barrier/Laser_Long.png");
}