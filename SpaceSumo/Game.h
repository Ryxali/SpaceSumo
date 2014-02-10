#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Clock.hpp>
#include "RenderList.h"
#include <Common\Config.h>
#include "GameData.h"
#include "StateList.h"

class Game
{
public:
	Game();
	~Game();
	void start();
private:
	void loop();
	void update(int delta);
	void preDraw();
	void draw();
	GameData mGameData;
	StateList mStates;
	Config mConfig;
	sf::RenderWindow mWindow;
	sf::View mView;
	RenderList mRenderList;
	sf::Clock mDeltaClock;
	
};

