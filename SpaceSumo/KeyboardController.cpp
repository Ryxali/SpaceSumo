#include "stdafx.h"
#include "KeyboardController.h"
#include "GameData.h"
#include <SFML\Window\Keyboard.hpp>


KeyboardController::KeyboardController()
{
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

			if(evt.key.code == sf::Keyboard::W) 
			{
				set(UP, true);
			}
			else
			{
				set(UP, false);
			}

			if(evt.key.code == sf::Keyboard::S) 
			{
				set(DOWN, true);
			}
			else
			{
				set(DOWN, false);
			}

			if(evt.key.code == sf::Keyboard::A) 
			{
				set(LEFT, true);
			}
			else
			{
				set(LEFT, false);
			}
			
			if(evt.key.code == sf::Keyboard::D) 
			{
				set(RIGHT, true);
			}
			else
			{
				set(RIGHT, false);
			}

			if(evt.key.code == sf::Keyboard::E) 
			{
				set(ACTIVATE, true);
			}
			else
			{
				set(ACTIVATE, false);
			}

			if(evt.key.code == sf::Keyboard::Space) 
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
