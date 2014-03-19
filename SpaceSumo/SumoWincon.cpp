#include "stdafx.h"
#include "SumoWincon.h"
#include "SpaceManImp.h"
#include "EntityImp.h"
#include <iostream>

SumoWincon::SumoWincon()
	: mGameTime(125000),
	mStartedTimer(false)
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

void SumoWincon::timerStart()
{
	mGameClock.restart();
	mStartedTimer = true;
}

bool SumoWincon::getTimerStarted()
{
	return mStartedTimer;
}

bool SumoWincon::getTimerExpired()
{
	if( mGameClock.getElapsedTime().asMilliseconds() == mGameTime )
	{
		return true;
	}
	else
	{
		return false;
	}

}

int SumoWincon::getTimeLeft()
{
	return mGameTime - mGameClock.getElapsedTime().asMilliseconds();
}
