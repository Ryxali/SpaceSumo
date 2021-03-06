#include "stdafx.h"
#include "KeyboardController.h"
#include "GameData.h"
#include <SFML\Window\Keyboard.hpp>
#include <Common\stringH.h>
#include <iostream>

KeyboardController::KeyboardController(int playerindex, Config& config): 
	mUp(str::toKey(config.getValue<std::string>("up"))),
	mDown(str::toKey(config.getValue<std::string>("down"))),
	mLeft(str::toKey(config.getValue<std::string>("left"))),
	mRight(str::toKey(config.getValue<std::string>("right"))),
	mEnter(str::toKey(config.getValue<std::string>("enter"))),
	mForward(str::toKey(config.getValue<std::string>("forward"))),
	mPush(str::toKey(config.getValue<std::string>("push"))),
	mActivate(str::toKey(config.getValue<std::string>("activate")))
{
	mPlayerIndex = playerindex;
}


KeyboardController::~KeyboardController()
{
}

bool KeyboardController::isActiveReset(Control ctrl)
{
	bool stat(mRStatus.at(ctrl));
	mRStatus.set(ctrl, false);
	return stat;
}

void KeyboardController::set(Control ctrl, bool status)
{
	Controller::set(ctrl, status);
	mRStatus.set(ctrl, status);
}

void KeyboardController::update(GameData& data)
{
	sf::Event evt;
	while(data.input.pop_front(evt))
	{
		switch (evt.type)
		{
		case sf::Event::KeyPressed:
			if(evt.key.code == mUp) 
			{
				set(UP, true);
			}
			

			if(evt.key.code == mDown) 
			{
				set(DOWN, true);
			}
			

			if(evt.key.code == mLeft) 
			{
				set(LEFT, true);
			}
			
			
			if(evt.key.code == mRight) 
			{
				set(RIGHT, true);
			}
			
			if(evt.key.code == mEnter) 
			{
				set(ENTER, true);
			}

			if(evt.key.code == mForward) 
			{
				set(FORWARD, true);
			}

			if(evt.key.code == mActivate) 
			{
				set(ACTIVATE, true);
			}
			

			if(evt.key.code == mPush) 
			{
				set(PUSH, true);
			}
			
			
			data.input.add(evt);
			
		break;
		
		case sf::Event::KeyReleased:
			if(evt.key.code == mUp) 
			{
				set(UP, false);
			}
			

			if(evt.key.code == mDown) 
			{
				set(DOWN, false);
			}
			

			if(evt.key.code == mLeft) 
			{
				set(LEFT, false);
			}
			
			
			if(evt.key.code == mRight) 
			{
				set(RIGHT, false);
			}
			
			if(evt.key.code == mEnter) 
			{
				set(ENTER, false);
			}

			if(evt.key.code == mForward) 
			{
				set(FORWARD, false);
			}

			if(evt.key.code == mActivate) 
			{
				set(ACTIVATE, false);
			}
			

			if(evt.key.code == mPush) 
			{
				set(PUSH,false);
			}
			
			data.input.add(evt);
			
		break;
		
			default:
			data.input.add(evt);
			break;
		}
			
	}
}
