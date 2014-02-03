#include "stdafx.h"
#include "Game.h"
#include <Common\Config.h>

Game::Game() : mConfig("config.cfg", true), 
	mWindow
	(
	sf::VideoMode(
	mConfig.getValue<int>("screenWidth"),
	mConfig.getValue<int>("screenHeight")),
	"Test",
	mConfig.getValue<int>("fullscreen")
	),
	mRenderList()
{
	mWindow.setFramerateLimit(160);
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
		mWindow.clear();

		update();
		preDraw();
		draw();

		mWindow.display();
	}
}

void Game::update()
{

}

void Game::preDraw()
{
	// TODO curState.preDraw(renderList& list);
}

void Game::draw()
{

}