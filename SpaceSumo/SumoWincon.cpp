#include "stdafx.h"
#include "SumoWincon.h"
#include "SpaceManImp.h"
#include "EntityImp.h"

SumoWincon::SumoWincon()
{
}

SumoWincon::~SumoWincon()
{
}

void SumoWincon::update(GameData& data, GameStateData& gData, SpaceManImp*(&mSpacemen)[4])
{
	for( int i = 0; i < 3; i++)
	{
		if( (*mSpacemen)->respawning() )
		{
			(*mSpacemen)->decreaseLives();
		}
	}
}

void SumoWincon::draw(RenderList &list)
{

}