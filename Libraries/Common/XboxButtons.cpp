#include "stdafx.h"
#include "XboxButtons.h"
#include "error.h"

sf::Xbox::ControllerStatus::ControllerStatus() : 
	leftStick(sf::Joystick::Axis::X, sf::Joystick::Axis::Y),
	rightStick(sf::Joystick::Axis::U, sf::Joystick::Axis::R),
	leftTrigger(sf::Joystick::Axis::Z),
	rightTrigger(sf::Joystick::Axis::Z)
{

}
sf::Xbox::ControllerStatus::AnalogStatus::AnalogStatus(sf::Joystick::Axis aliasX, sf::Joystick::Axis aliasY)
	: aliasX(aliasX), aliasY(aliasY), statusX(IDLE), statusY(IDLE)
{

}

sf::Xbox::ControllerStatus::TriggerStatus::TriggerStatus(sf::Joystick::Axis alias) : alias(alias)
{
}

void sf::Xbox::getAnalogEvent(const sf::Event::JoystickMoveEvent &evt, ControllerStatus &status)
{
	switch(evt.axis)
	{
	case sf::Joystick::Axis::X:
		if(evt.position < -30)
		{
			status.leftStick.statusX = sf::Xbox::ControllerStatus::NEGATIVE;
		}
		else if(evt.position > 30)
		{
			status.leftStick.statusX = sf::Xbox::ControllerStatus::POSITIVE;
		}
		else
		{
			status.leftStick.statusX = sf::Xbox::ControllerStatus::IDLE;
		}
		break;

	case sf::Joystick::Axis::Y:
		if(evt.position < -30)
		{
			status.leftStick.statusY = sf::Xbox::ControllerStatus::POSITIVE;
		}
		else if(evt.position > 30)
		{
			status.leftStick.statusY = sf::Xbox::ControllerStatus::NEGATIVE;
		}
		else
		{
			status.leftStick.statusY = sf::Xbox::ControllerStatus::IDLE;
		}
		break;

	case sf::Joystick::Axis::R:
		if(evt.position < -30)
		{
			status.rightStick.statusY = sf::Xbox::ControllerStatus::POSITIVE;
		}
		else if(evt.position > 30)
		{
			status.rightStick.statusY = sf::Xbox::ControllerStatus::NEGATIVE;
		}
		else
		{
			status.rightStick.statusY = sf::Xbox::ControllerStatus::IDLE;
		}
		break;

	case sf::Joystick::Axis::U:
		if(evt.position < -30)
		{
			status.rightStick.statusX = sf::Xbox::ControllerStatus::NEGATIVE;
		}
		else if(evt.position > 30)
		{
			status.rightStick.statusX = sf::Xbox::ControllerStatus::POSITIVE;
		}
		else
		{
			status.rightStick.statusX = sf::Xbox::ControllerStatus::IDLE;
		}
		break;

	case sf::Joystick::Axis::Z:
		if(evt.position < -30)
		{
			status.rightTrigger.status = sf::Xbox::ControllerStatus::POSITIVE;
		}
		else if(evt.position < 0)
		{
			status.rightTrigger.status = sf::Xbox::ControllerStatus::IDLE;
		}
		else if(evt.position > 30)
		{
			status.leftTrigger.status = sf::Xbox::ControllerStatus::POSITIVE;
		}
		else if(evt.position > 0)
		{
			status.leftTrigger.status = sf::Xbox::ControllerStatus::IDLE;
		}
		else
		{
			status.leftTrigger.status = sf::Xbox::ControllerStatus::IDLE;
			status.rightTrigger.status = sf::Xbox::ControllerStatus::IDLE;
		}
		break;
	}
}