#pragma once
#include "Wincon.h"
#include <SFML\System\Clock.hpp>

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
	bool mStartedTimer;

	int mGameTime;
	sf::Clock mGameClock;
};

