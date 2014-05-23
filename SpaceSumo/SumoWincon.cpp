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
	: mLockPlayers(true),
	mGameTime(240000),
	mLoadedSpacemen(false),
	mStartedTimer(false),
	mBrawl(res::getTexture("res/img/UI/hud/321brawl.png"), "res/img/UI/hud/321brawl.cfg", 10.f),
	mRunCountdown(false),
	mCountdownDone(false),
	mGameHasStarted(false),
	mHasPlayed(false),
	mCountDown(4000),
	mStartTimeout(10000),
	m321brawl(soundFac::createSound("res/sound/voice/Announcer/Announcer_Matchstart-003.spf")),
	mBlueWin(res::getTexture("res/img/UI/hud/win_blue_still.png"), 11.f),
	mRedWin(res::getTexture("res/img/UI/hud/win_red_still.png"), 12.f),
	mGreenWin(res::getTexture("res/img/UI/hud/win_green_still.png"), 13.f),
	mYellowWin(res::getTexture("res/img/UI/hud/win_yellow_still.png"),  14.f),
	mShowBlueWin(false),
	mShowRedWin(false),
	mShowGreenWin(false),
	mShowYellowWin(false),
	mRunEndgame(true)
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
			mSpacemenArray[i] = mSpacemen[i];
			mLead[i] = mSpacemen[i];
		}
		mLoadedSpacemen = true;
	}

	if( mLockPlayers )
	{
		for(int i = 0; i < 4; i++ )
		{
			if(mSpacemenArray[i] != 0 )
			{
				mSpacemenArray[i]->resetPosition();
			}

		}
	}

	if( mStartGame.getElapsedTime().asMilliseconds() > mStartTimeout && !mGameHasStarted )
	{
		mRunCountdown = true;
		mGameHasStarted = true;
		mCountDownClock.restart();
	}

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

	countdown(mRunCountdown);
	endgame(mRunEndgame);
}

void SumoWincon::draw(RenderList &list)
{

	mBlueWin.getSprite().setPosition(WINDOW_SIZE.x/2, WINDOW_SIZE.y/2);
	mBlueWin.getSprite().setOrigin(mBlueWin.getSprite().getLocalBounds().width/2, mBlueWin.getSprite().getLocalBounds().height/2);

	mRedWin.getSprite().setPosition(WINDOW_SIZE.x/2, WINDOW_SIZE.y/2);
	mRedWin.getSprite().setOrigin(mRedWin.getSprite().getLocalBounds().width/2, mRedWin.getSprite().getLocalBounds().height/2);

	mGreenWin.getSprite().setPosition(WINDOW_SIZE.x/2, WINDOW_SIZE.y/2);
	mGreenWin.getSprite().setOrigin(mGreenWin.getSprite().getLocalBounds().width/2, mGreenWin.getSprite().getLocalBounds().height/2);

	mYellowWin.getSprite().setPosition(WINDOW_SIZE.x/2, WINDOW_SIZE.y/2);
	mYellowWin.getSprite().setOrigin(mYellowWin.getSprite().getLocalBounds().width/2, mYellowWin.getSprite().getLocalBounds().height/2);


	if( mRunCountdown)
	{
		list.addSprite(mBrawl);
	}

	if(mShowBlueWin) // blue win animation
	{
		list.addSprite(mBlueWin);
	}
	if(mShowRedWin)  // red win animation
	{
		list.addSprite(mRedWin);
	}
	if(mShowGreenWin) // green win animation
	{
		list.addSprite(mGreenWin);
	}
	if(mShowYellowWin) // yellow win animation
	{
		list.addSprite(mYellowWin);
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
			mRunCountdown = false;
			mCountdownDone = true;
			mLockPlayers = false;
		}
		else
		{
			//pauses the clock so it doesnt count before the game has started
			mGameClock.restart();
		}

	}
	else if( !run && !mCountdownDone )
	{
		//pauses the clock so it doesnt count before the game has started
		mGameClock.restart();
	}
}

void SumoWincon::resetClocks()
{
	mGameClock.restart();
	mCountDownClock.restart();
}

void SumoWincon::endgame(bool status)
{

	if( status )
	{
		int pLeft = 0;
		int players = 4;
		for(int i = 0; i < 4; i++ )
		{
			if( mSpacemenArray[i] == 0 )
			{
				players--;
				
			}
			else
			{
				if(mSpacemenArray[i]->getHead().getScore() > 0)
					++pLeft;
			}
		}

		if(mGameClock.getElapsedTime().asMilliseconds() > mGameTime || pLeft <= 1)
		{


			SpaceManImp* temp;
			for( int i = 0; i < players; i++)
			{
				for(int y = 0; y < players; y++)
				{
					if(mLead[i]->getHead().getScore() > mLead[y]->getHead().getScore())
					{
						temp = mLead[y];
						mLead[y] = mLead[i];
						mLead[i] = temp;
					}
				}
			}

			if(mLead[0]->getIndex() == 1 )
			{
				std::cout << "blue wins" <<std::endl;
				mShowBlueWin = true;
				mRunEndgame = false;
				mLockPlayers = true;
			}
			else if(mLead[0]->getIndex() == 2 )
			{
				std::cout << "red wins" <<std::endl;
				mShowRedWin = true;
				mRunEndgame = false;
				mLockPlayers = true;
			}
			else if(mLead[0]->getIndex() == 3 )
			{
				std::cout << "green wins" <<std::endl;
				mShowGreenWin = true;
				mRunEndgame = false;
				mLockPlayers = true;
			}
			else if(mLead[0]->getIndex() == 4 )
			{
				std::cout << "yellow wins" <<std::endl;
				mShowYellowWin = true;
				mRunEndgame = false;
				mLockPlayers = true;
			}

		}
	}
}
