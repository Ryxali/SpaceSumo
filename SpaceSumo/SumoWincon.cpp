#include "stdafx.h"
#include "SumoWincon.h"
#include "SpaceManImp.h"
#include "EntityImp.h"
#include "consts.h"
#include <ResourceManager\RHandle.h>
#include <iostream>

SumoWincon::SumoWincon()
	: mGameTime(125000),
	mStartedTimer(false),
	mBrawl(res::getTexture("res/img/UI/hud/321brawl.png"), "res/img/UI/hud/321brawl.cfg", 10.f),
	mGameHasStarted(false),
	mCountdownStarted(false),
	mCountdownDone(false),
	mPregameDuration(7000),
	mCountdownDuration(4000)
{
	mBrawl.getSprite().setPosition(WINDOW_SIZE.x/2,WINDOW_SIZE.y/2);
	mBrawl.getSprite().setOrigin(mBrawl.getSprite().getLocalBounds().width/2, mBrawl.getSprite().getLocalBounds().height/2);
}

SumoWincon::~SumoWincon()
{
}

void SumoWincon::update(GameData& data, GameStateData& gData, SpaceManImp*(&mSpacemen)[4])
{
	countdown();
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
	if( mCountdownStarted && !mCountdownDone)
	{
		list.addSprite(mBrawl);
	}

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

void SumoWincon::countdown()
{
	if( mPregameClock.getElapsedTime().asMilliseconds() == mPregameDuration)
	{
		if( !mCountdownStarted )
		{
			mCountdownClock.restart();
			mCountdownStarted = true;
		}
	}

	if( mCountdownClock.getElapsedTime().asMilliseconds() == mCountdownDuration )
	{
		mCountdownDone = true;
	}
}
