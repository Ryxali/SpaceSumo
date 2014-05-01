#include "stdafx.h"
#include "XController.h"
#include "GameData.h"
#include <Common\XboxButtons.h>
#include <iostream>
#include <Common\stringH.h>


XController::XController(int controllerIndex, int playerIndex, Config& conf):
	mControllerIndex(controllerIndex),
	mUp(str::toXboxKey(conf.getValue<std::string>("up"))),
	mDown(str::toXboxKey(conf.getValue<std::string>("down"))),
	mLeft(str::toXboxKey(conf.getValue<std::string>("left"))),
	mRight(str::toXboxKey(conf.getValue<std::string>("right"))),
	mEnter(str::toXboxKey(conf.getValue<std::string>("enter"))),
	mForward(str::toXboxKey(conf.getValue<std::string>("forward"))),
	mActivate(str::toXboxKey(conf.getValue<std::string>("activate"))),
	mPush(str::toXboxKey(conf.getValue<std::string>("push"))),
	mRepeatTime(conf.getValue<int>("repeatTime"))
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
bool XController::hasCode(sf::Keyboard::Key key)
{
	return false;
}
bool XController::isActiveReset(Control ctrl)
{
	if(mStatus.at(ctrl))
	{
		if(mActiveR[ctrl])
		{
			mActiveR.set(ctrl, false);
			mTimers[ctrl].restart();
			return true;
		}
		else if(mTimers[ctrl].getElapsedTime().asMilliseconds() > mRepeatTime)
		{
			mTimers[ctrl].restart();
			return true;
		}
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
		switch (evt.type)
		{
		case sf::Event::JoystickButtonPressed:

			if(evt.joystickButton.joystickId == mControllerIndex)
			{
				bool breakmaybe = false;
				if(evt.joystickButton.button == mActivate) // A
				{
					set(ACTIVATE, true);
					breakmaybe = true;
				}

				if(evt.joystickButton.button == mPush) // B
				{
					set(PUSH, true);
					breakmaybe = true;
				}

				if(evt.joystickButton.button == mEnter) // B
				{
					set(ENTER, true);
					breakmaybe = true;
				}

				if(evt.joystickButton.button == mForward) // B
				{
					set(FORWARD, true);
					breakmaybe = true;
				}
				if(breakmaybe)break;
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
	
		case sf::Event::JoystickButtonReleased:
			if(evt.joystickButton.joystickId == mControllerIndex)
			{
				bool breakmaybe = false;
				if(evt.joystickButton.button == mActivate) // A
				{
					set(ACTIVATE, false);
					breakmaybe = true;
				}

				if(evt.joystickButton.button == mPush) // B
				{
					set(PUSH, false);
					breakmaybe = true;
				}

				if(evt.joystickButton.button == mEnter) // B
				{
					set(ENTER, false);
					breakmaybe = true;
				}

				if(evt.joystickButton.button == mForward) // B
				{
					set(FORWARD, false);
					breakmaybe = true;
				}
				if(breakmaybe)break;
			}
		default:
			data.input.add(evt);
			break;
		
	}

	set(UP, sf::Joystick::getAxisPosition(mControllerIndex, (sf::Joystick::Axis)mUp) < -30);
	set(DOWN, sf::Joystick::getAxisPosition(mControllerIndex, (sf::Joystick::Axis)mDown) > 30);
	set(LEFT, sf::Joystick::getAxisPosition(mControllerIndex, (sf::Joystick::Axis)mLeft) < -30);
	set(RIGHT, sf::Joystick::getAxisPosition(mControllerIndex, (sf::Joystick::Axis)mRight) > 30);}
}


void XController::set(Control ctrl, bool status)
{
	if(isActive(ctrl) != status)
		mActiveR.set(ctrl, status);
	Controller::set(ctrl, status);
}