#include "stdafx.h"
#include "Game.h"
#include <Common\Config.h>
#include <SFML\Window\Keyboard.hpp>
#include "SpaceManImp.h"

Game::Game() : mConfig("res/conf/main.cfg", true), 
	mWindow
	(
	sf::VideoMode(
	mConfig.getValue<int>("screenWidth"),
	mConfig.getValue<int>("screenHeight")),
	"Test",
	mConfig.getValue<int>("fullscreen")),
	mRenderList(),
	mGravity(b2Vec2( 0 , 0 )),
	mWorld(new b2World(mGravity)),
	mSpaceman(sf::Keyboard::Up,
	sf::Keyboard::Down,
	sf::Keyboard::Right,
	sf::Keyboard::Left,
	sf::Keyboard::Space,
	mWorld)
{
	mWindow.setFramerateLimit(160);
	mWindow.setVerticalSyncEnabled(mConfig.getValue<bool>("vsync"));

}


Game::~Game()
{
	mConfig.saveConfigChange();
}

void Game::start()
{
	
	
	
	
	

	while(mWindow.isOpen())
	{
		loop();
	}
}

void Game::loop()
{
	sf::Event evt;
	// Loop runs through all new events
	while(mWindow.isOpen())
	{

		float timeStep = 1/60.f;
		mWorld->Step(timeStep,8,3);

		while(mWindow.pollEvent(evt))
		{
			// Switch-statements can be used instead of if-statements, good in case we have many eventtypes to handle.
			if(evt.type == sf::Event::Closed)
			{
				mWindow.close();
			}
			else if(evt.type == sf::Event::KeyPressed) 
			{
				if(evt.key.code == sf::Keyboard::Escape) 
				{
					mWindow.close();
					
				}
			}
		}
		mWindow.clear(sf::Color::Blue);

		update();
		preDraw();
		draw();

		mWindow.display();
	}
}

void Game::update()
{
	mSpaceman.update(1);
}

void Game::preDraw()
{
	// TODO curState.preDraw(renderList& list);
}

void Game::draw()
{
	mWindow.draw(mSpaceman.getShape());
}