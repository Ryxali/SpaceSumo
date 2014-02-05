#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML\Window.hpp>
#include "RenderList.h"
#include "SpaceManImp.h"
#include <Common\Config.h>
#include <Box2D/Box2D.h>
#include <ResourceManager\Animation.h>
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
	b2Vec2 mGravity;
	b2World* mWorld;
	SpaceManImp mSpaceman;
	SpaceManImp mSpaceman2;
	Config mConfig;
	sf::RenderWindow mWindow;
	sf::View mView;
	RenderList mRenderList;

	sf::Clock mDeltaClock;
	
};

