#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Clock.hpp>
#include "RenderList.h"
#include <Common\Config.h>
#include "GameData.h"
#include "GameStateList.h"
#include "ContactListener.h"
#include "KeyboardController.h"
#include <SFML/Audio/Listener.hpp>

class Game
{
public:
	Game();
	void start();
private:
	void loop();
	void update(int delta);
	void preDraw();
	void draw();
	void cleanUp();
	void close();
	GameData mGameData;
	GameStateList mStates;
	Config mConfig;
	sf::RenderWindow mWindow;
	sf::View mView;
	RenderList mRenderList;
	sf::Clock mDeltaClock;
	ContactListener mListener;
	
	
};

