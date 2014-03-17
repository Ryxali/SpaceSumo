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
	for( int i = 0; i < 4; i++)
	{
		if( mSpacemen[i] != 0 )
		{
			if( mSpacemen[i]->respawning() )
			{
				mSpacemen[i]->decreaseLives();
			}
		}
	}
}

void SumoWincon::draw(RenderList &list)
{

}