#include "stdafx.h"
#include "Game.h"
#include <Common\Config.h>
#include <SFML\Window\Keyboard.hpp>
#include "MenuState.h"
#include "GameState.h"
#include <Common\SVector.h>
#include <ResourceManager\soundFac.h>
#include "KeyboardController.h"
#include "XController.h"
#include <Common/XboxButtons.h>
#include <iostream>

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
	mWindow.setKeyRepeatEnabled(false);


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
			if(evt.key.code == sf::Keyboard::Escape) 
			{
				close();
				return;
				break;
			}
			else if(evt.key.code == sf::Keyboard::Return)
			{
				mGameData.controlList.add( new KeyboardController(mGameData.nJoysticks+mGameData.nKeyboards+1, Config("res/conf/controls/keyboard_" + std::to_string(mGameData.nKeyboards+1) + ".cfg")));
				++mGameData.nKeyboards;
				break;
			}
			
		case sf::Event::JoystickButtonPressed:
			if(evt.joystickButton.button == sf::Xbox::START)
			{
				mGameData.controlList.add(new XController(evt.joystickButton.joystickId, mGameData.nJoysticks+mGameData.nKeyboards+1, (Config("res/conf/controls/joystick_base.cfg"))));
				++mGameData.nJoysticks;
				break;
			}
		default:
			mGameData.input.add(evt);
			break;
		}
	}
	mGameData.mPos = (sf::Vector2f)sf::Mouse::getPosition(mWindow) * (mView.getSize()/(sf::Vector2f)mWindow.getSize());
	mWindow.clear(sf::Color::White);
	mGameData.controlList.update(mGameData);
	update(delta.asMilliseconds());
	preDraw();
	draw();
	cleanUp();
	mGameData.input.clear();
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