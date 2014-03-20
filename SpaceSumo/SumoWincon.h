#pragma once
#include "Wincon.h"
#include <SFML\System\Clock.hpp>
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

	void timerStart();
	bool getTimerStarted();
	bool getTimerExpired();
	int getTimeLeft();

	void resetClocks();

private:
	bool mLoadedSpacemen;
	// start game
	Animation mBrawl;
	void countdown(bool run);
	bool mRunCountdown;
	bool mCountdownDone;
	bool mGameHasStarted;
	bool mStartedTimer;

	int mGameTime;
	sf::Clock mGameClock;

	int mCountDown;
	sf::Clock mCountDownClock;
	Playable* m321brawl;
	bool mHasPlayed;

	// stop game
	void endgame(bool);

	SpaceManImp* mSpacemenArray[4];
	SpaceManImp* mLead[4];
	int mPoints[4];
};

