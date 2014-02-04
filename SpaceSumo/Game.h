#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML\Window.hpp>
#include "RenderList.h"
#include <Common\Config.h>
#include <Box2D/Box2D.h>

class Game
{
public:
	Game();
	~Game();
	void start();
private:
	void loop();
	void update();
	void preDraw();
	void draw();
	Config mConfig;
	sf::RenderWindow mWindow;
	sf::View mView;
	RenderList mRenderList;

	// Box2D stuff
	b2World* myWorld;
	
};

