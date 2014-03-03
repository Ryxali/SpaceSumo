#include "stdafx.h"
#include "Game.h"
#include <Common\Config.h>
#include <SFML\Window\Keyboard.hpp>
#include "MenuState.h"
#include "GameState.h"
#include <Common\SVector.h>
#include <ResourceManager\soundFac.h>

sf::Vector2f operator/(const sf::Vector2f &v0, const sf::Vector2f &v1)
{
	return sf::Vector2f(v0.x/v1.x, v0.y/v1.y);
}

sf::Vector2f operator*(const sf::Vector2f &v0, const sf::Vector2f &v1)
{
	return sf::Vector2f(v0.x*v1.x, v0.y*v1.y);
}

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
	mGameData.world.SetContactListener(&mListener);
	soundFac::createSound("res/sound/jet.spf", mGameData.soundlist)->play();
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
			close();
			return;
			break;
		case sf::Event::KeyPressed:
			if(evt.key.code == sf::Keyboard::Escape || evt.key.code == sf::Keyboard::R) 
			{
				close();
				return;
				break;
			}
		default:
			mGameData.input.add(evt);
			break;
		}
	}
	mGameData.mPos = (sf::Vector2f)sf::Mouse::getPosition(mWindow) * (mView.getSize()/(sf::Vector2f)mWindow.getSize());
	mWindow.clear(sf::Color::White);
	update(delta.asMilliseconds());
	preDraw();
	draw();
	cleanUp();
}

void Game::update(int delta)
{
	mStates.getCurrent().update(mGameData, delta);
	mGameData.soundlist.update(mGameData);
}

void Game::preDraw()
{
	mStates.getCurrent().draw(mRenderList);
}

void Game::draw()
{
	mRenderList.render(mWindow);
	mWindow.display();
}

void Game::cleanUp()
{
	mStates.getCurrent().cleanUp();
	mStates.sync();
}

void Game::close()
{
	mStates.getCurrent().close();
	mWindow.close();
}