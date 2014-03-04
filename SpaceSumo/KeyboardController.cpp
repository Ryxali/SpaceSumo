#include "stdafx.h"
#include "KeyboardController.h"
#include "GameData.h"
#include <SFML\Window\Keyboard.hpp>
#include <Common\stringH.h>

KeyboardController::KeyboardController(int playerindex, Config& config): 
	mUp(str::toKey(config.getValue<std::string>("up"))),
	mDown(str::toKey(config.getValue<std::string>("down"))),
	mLeft(str::toKey(config.getValue<std::string>("left"))),
	mRight(str::toKey(config.getValue<std::string>("right"))),
	mPush(str::toKey(config.getValue<std::string>("push"))),
	mActivate(str::toKey(config.getValue<std::string>("activate")))
{
	mPlayerIndex = playerindex;
}


KeyboardController::~KeyboardController()
{
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
			else
			{
				set(UP, false);
			}

			if(evt.key.code == mDown) 
			{
				set(DOWN, true);
			}
			else
			{
				set(DOWN, false);
			}

			if(evt.key.code == mLeft) 
			{
				set(LEFT, true);
			}
			else
			{
				set(LEFT, false);
			}
			
			if(evt.key.code == mRight) 
			{
				set(RIGHT, true);
			}
			else
			{
				set(RIGHT, false);
			}

			if(evt.key.code == mActivate) 
			{
				set(ACTIVATE, true);
			}
			else
			{
				set(ACTIVATE, false);
			}

			if(evt.key.code == mPush) 
			{
				set(PUSH,true);
			}
			else
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
