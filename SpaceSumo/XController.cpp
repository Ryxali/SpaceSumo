#include "stdafx.h"
#include "XController.h"
#include "GameData.h"
#include <Common\XboxButtons.h>



XController::XController(int controllerIndex, int playerIndex, Config& conf):
	mControllerIndex(controllerIndex)
{
	for(int i = 0; i < MAX_SIZE; ++i)
	{
		mTimers.emplace_back();
	}
	mPlayerIndex = playerIndex;
}

XController::~XController()
{
}

bool XController::isActiveReset(Control ctrl)
{
	int i = mTimers[ctrl].getElapsedTime().asMilliseconds();
	if(mStatus.at(ctrl))
	{
		if(mTimers[ctrl].getElapsedTime().asMilliseconds() > 500)
		{
			mTimers[ctrl].restart();
			return true;
		}
	}
	else
	{
		mTimers[ctrl].restart();
		int i = mTimers[ctrl].getElapsedTime().asMilliseconds();
	}
	return false;
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
		sf::Xbox::ControllerStatus cs;
		switch (evt.type)
		{
		case sf::Event::JoystickButtonPressed:

			if(evt.joystickButton.joystickId == mControllerIndex)
			{
				/*if(evt.joystickButton.button == 0) // A
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
				}*/
				break;
			}
			

		case sf::Event::JoystickMoved:
			if(evt.joystickMove.joystickId == mControllerIndex)
			{
				sf::Xbox::getAnalogEvent(evt.joystickMove, cs);
				if(cs.leftStick.statusY == sf::Xbox::ControllerStatus::NEGATIVE)
				{
					set(UP, true);
					set(DOWN, false);
				}
				else if(cs.leftStick.statusY == sf::Xbox::ControllerStatus::NEGATIVE)
				{
					set(UP, false);
					set(DOWN, true);
				}
				else if(cs.leftStick.statusY == sf::Xbox::ControllerStatus::IDLE)
				{
					set(UP, false);
					set(DOWN, false);
				}
				break;
			}
			/*if(evt.joystickMove.axis == sf::Joystick::Y) // left stick horizontal
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

			break;*/
		default:
			data.input.add(evt);
			break;
		}
	}
}
