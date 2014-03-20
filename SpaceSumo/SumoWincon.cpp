#include "stdafx.h"
#include "SumoWincon.h"
#include "SpaceManImp.h"
#include "EntityImp.h"
#include "consts.h"
#include <ResourceManager\RHandle.h>
#include <ResourceManager\soundFac.h>
#include "Head.h"
#include <iostream>

SumoWincon::SumoWincon()
	: mGameTime(120000),
	mLoadedSpacemen(false),
	mStartedTimer(false),
	mBrawl(res::getTexture("res/img/UI/hud/321brawl.png"), "res/img/UI/hud/321brawl.cfg", 10.f),
	mRunCountdown(false),
	mCountdownDone(false),
	mGameHasStarted(false),
	mHasPlayed(false),
	mCountDown(4000),
	m321brawl(soundFac::createSound("res/sound/voice/Announcer/Announcer_Matchstart-003.spf"))
{
	mBrawl.getSprite().setPosition(WINDOW_SIZE.x/2,WINDOW_SIZE.y/2);
	mBrawl.getSprite().setOrigin(mBrawl.getSprite().getLocalBounds().width/2, mBrawl.getSprite().getLocalBounds().height/2);
}

SumoWincon::~SumoWincon()
{
}

void SumoWincon::update(GameData& data, GameStateData& gData, SpaceManImp*(&mSpacemen)[4])
{
	if( !mLoadedSpacemen )
	{
		for( int i = 0; i < 4; i++ )
		{
			mSpacemenVec.push_back(mSpacemen[i]);
		}
		mLoadedSpacemen = true;
	}


	if( sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !mGameHasStarted )
	{
		mRunCountdown = true;
		mGameHasStarted = true;
		mCountDownClock.restart();
	}

	countdown(mRunCountdown);

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
	if( mRunCountdown )
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

void SumoWincon::countdown(bool run)
{
	if(run)
	{
		if(!m321brawl->isPlaying() && !mHasPlayed )
		{
			m321brawl->play();
			mHasPlayed = true;
		}

		if( mCountDownClock.getElapsedTime().asMilliseconds() > mCountDown )
		{
			//game starts
			// TODO mSpacemen.disable(false);
			mRunCountdown = false;
			mCountdownDone = true;
		}
		else
		{
			//pauses the clock so it doesnt count before the game has started
			mGameClock.restart();
			// TODO mSpacemen.disable(true);
		}

	}
	else if( !run && !mCountdownDone )
	{
		//pauses the clock so it doesnt count before the game has started
		mGameClock.restart();
		// TODO mSpacemen.disable(true);
	}
}

void SumoWincon::resetClocks()
{
	mGameClock.restart();
	mCountDownClock.restart();
}

void SumoWincon::endgame(bool status)
{
	for( auto it = mSpacemenVec.begin(); it != mSpacemenVec.end(); it++ )
	{
		(*it)->getHead().getScore();
	}

}
