#include "stdafx.h"
#include "XController.h"
#include "GameData.h"

XController::XController(int controllerIndex, int playerIndex, Config& conf):
	mControllerIndex(controllerIndex)
{
	mPlayerIndex = playerIndex;
}

XController::~XController()
{
}


bool XController::isConnected( int controllerIndex )
{
	if( sf::Joystick::isConnected(controllerIndex) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void XController::update(GameData& data)
{

	sf::Event evt;
	while(data.input.pop_front(evt))
	{
		switch (evt.type)
		{
		case sf::Event::JoystickButtonPressed:
			
			if(evt.joystickButton.joystickId == mControllerIndex)
			{
				if(evt.joystickButton.button == 0) // A
				{
					set(UP, true);
				}
				else
				{
					set(UP, false);
				}

				if(evt.joystickButton.button == 1) // B
				{
					set(ACTIVATE, true);
				}
				else
				{
					set(ACTIVATE, false);
				}

				if(evt.joystickButton.button == 2) // X
				{
					set(PUSH,true);
				}
				else
				{
					set(PUSH,false);
				}

			}
			else
			{
				data.input.add(evt);
			}
			break;

		case sf::Event::JoystickMoved:

			if(evt.joystickMove.axis == sf::Joystick::Y) // left stick horizontal
			{

				// stick is moved to the left
				if( evt.joystickMove.position < 0 )
				{
					set(LEFT,true);
				}
				else
				{
					set(LEFT,false);
				}

				// left joystick is moved
				if( evt.joystickMove.axis == sf::Joystick::X)
				{
					//if it is moved to the left
					if(evt.joystickMove.position < -30 )
					{
						set(LEFT,true);
					}
					else
					{
						set(LEFT,false);
					}

					//if it is moved to the right
					if(evt.joystickMove.position > 30 )
					{
						set(RIGHT,true);
					}
					else
					{
						set(RIGHT,false);
					}
				}
			}
			else
			{
				// config input
			}

			break;
		default:
			data.input.add(evt);
			break;
		}
	}
	data.input.pop_front(evt);
}
