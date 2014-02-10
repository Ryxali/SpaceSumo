#include "stdafx.h"
#include "Game.h"
#include <Common\Config.h>
#include <SFML\Window\Keyboard.hpp>
#include "MenuState.h"
#include "GameState.h"
#define NO_MEMORY_TRACKING

Game::Game() :
	mConfig("res/conf/main.cfg", true), 
	mWindow
	(
	sf::VideoMode(
	mConfig.getValue<int>("screenWidth"),
	mConfig.getValue<int>("screenHeight")),
	"Test",
	mConfig.getValue<int>("fullscreen")),
	mView(sf::FloatRect(0, 0, 1920, 1080)),
	mRenderList(),
	mGameData(),
	mStates(mGameData)
{
	mWindow.setFramerateLimit(160);
	mWindow.setVerticalSyncEnabled(mConfig.getValue<bool>("vsync"));
	mWindow.setView(mView);
	mStates.changeState(1);
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
		switch(evt.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::KeyPressed:
			if(evt.key.code == sf::Keyboard::Escape || evt.key.code == sf::Keyboard::R) 
			{
				mWindow.close();
				break;
			}
		default:
			mGameData.input.add(evt);
			break;
		}
	}
	mWindow.clear(sf::Color::White);
	update(delta.asMilliseconds());
	preDraw();
	draw();
}

void Game::update(int delta)
{
	mStates.getCurrent().update(mGameData, delta);
}

void Game::preDraw()
{
	mStates.getCurrent().draw(mRenderList);
	// TODO curState.preDraw(renderList& list);
}

void Game::draw()
{
	mRenderList.render(mWindow);
	mWindow.display();
}