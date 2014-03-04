#include "stdafx.h"
#include "SumoWincon.h"
#include "SpaceManImp.h"

SumoWincon::SumoWincon()
{
}


SumoWincon::~SumoWincon()
{
}

void SumoWincon::update(GameData& data, GameStateData& gData, SpaceManImp* subject)
{
	if(subject->isSlowlyDying())
		subject->addScore(-5);
}

void SumoWincon::draw(RenderList &list)
{

}