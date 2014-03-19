#pragma once
#include "Wincon.h"
#include <SFML\System\Clock.hpp>
#include <ResourceManager\Animation.h>

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

private:
	// start game
	Animation mBrawl;
	void countdown();
	bool mGameHasStarted;
	bool mCountdownStarted;
	bool mCountdownDone;
	bool mStartedTimer;
	
	int mPregameDuration;
	sf::Clock mPregameClock;

	int mCountdownDuration;
	sf::Clock mCountdownClock;

	int mGameTime;
	sf::Clock mGameClock;
};

