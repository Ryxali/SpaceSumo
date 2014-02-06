#include "stdafx.h"
#include "Game.h"
#include <Common\Config.h>
#include <SFML\Window\Keyboard.hpp>
#include "SpaceManImp.h"
#include <ResourceManager\RHandle.h>
#include <iostream>

Game::Game() : mConfig("res/conf/main.cfg", true), 
	mWindow
	(
	sf::VideoMode(
	mConfig.getValue<int>("screenWidth"),
	mConfig.getValue<int>("screenHeight")),
	"Test",
	mConfig.getValue<int>("fullscreen")),
	mRenderList(),
	mGameData(),
	mCurState(new MenuState())
{
	mWindow.setFramerateLimit(160);
	mWindow.setVerticalSyncEnabled(mConfig.getValue<bool>("vsync"));
}


Game::~Game()
{
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
	sf::Time delta = mDeltaClock.restart();
	sf::Event evt;
	// Loop runs through all new events
	mGameData.world.Step(delta.asSeconds(),8,3);

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
	mWindow.clear(sf::Color::White);
	update(delta.asMilliseconds());
	preDraw();
	draw();
	mWindow.display();
	
}

void Game::update(int delta)
{
	mCurState->update(mGameData);
}

void Game::preDraw()
{
	mCurState->draw(mRenderList);
	// TODO curState.preDraw(renderList& list);
}

void Game::draw()
{
	mRenderList.render(mWindow);
}