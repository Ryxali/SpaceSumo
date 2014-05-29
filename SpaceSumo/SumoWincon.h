#pragma once
#include "Wincon.h"
#include <SFML\System\Clock.hpp>
#include <ResourceManager\SSprite.h>
#include <ResourceManager\Animation.h>
#include <ResourceManager\Playable.h>
#include <SFML\Window\Keyboard.hpp>



class SumoWincon : public Wincon
{
public:
	SumoWincon();
	~SumoWincon();
	virtual void update(GameData&, GameStateData&, SpaceManImp*(&mSpacemen)[4]);
	virtual void draw(RenderList &list);
	bool gameOver();
	void timerStart();
	bool getTimerStarted();
	bool getTimerExpired();
	int getTimeLeft();

	void reset();

	void resetClocks();

private:
	bool mLoadedSpacemen;
	bool mLockPlayers;
	// start game
	Animation mBrawl;

	void countdown(bool run);
	bool mRunCountdown;
	bool mCountdownDone;
	bool mGameHasStarted;
	bool mStartedTimer;

	int mGameTime;			// the time of the whole game
	sf::Clock mGameClock;

	int mStartTimeout;			// timeout before the countdown starts
	sf::Clock mStartGame;

	int mCountDown;			// the "three two one go time"
	sf::Clock mCountDownClock;
	Playable* m321brawl;
	bool mHasPlayed;

	// stop game
	void endgame(bool);

	SpaceManImp* mSpacemenArray[4];
	SpaceManImp* mLead[4];
	int mPoints[4];

	SSprite mBlueWin;
	SSprite mRedWin;
	SSprite mGreenWin;
	SSprite mYellowWin;

	bool mShowBlueWin;
	bool mShowRedWin;
	bool mShowGreenWin;
	bool mShowYellowWin;

	bool mRunEndgame;


};

