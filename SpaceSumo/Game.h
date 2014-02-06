#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML\Window.hpp>
#include "RenderList.h"
#include "SpaceManImp.h"
#include <Common\Config.h>
#include <Box2D/Box2D.h>
#include <ResourceManager\Animation.h>
#include "GameData.h"
#include "MenuState.h"
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
	State* mCurState;
	Config mConfig;
	sf::RenderWindow mWindow;
	sf::View mView;
	RenderList mRenderList;
	sf::Clock mDeltaClock;
	
};

