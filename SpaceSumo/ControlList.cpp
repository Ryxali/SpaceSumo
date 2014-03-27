#include "stdafx.h"
#include "ControlList.h"
#include "Controller.h"
#include <Common\error.h>
#include "XController.h"
#include "KeyboardController.h"
ControlList::ControlList() : mNKeyboards(0), mNJoysticks(0), mNPlayers(0)
{
	for(int i = 0; i < 4; ++i)
	{
		mControlPool[i] = new KeyboardController(0, Config("res/conf/controls/keyboard_"+std::to_string(i+1)+".cfg"));
		mControlPool[4+i] = new XController(i, 0, Config("res/conf/controls/joystick_base.cfg"));
		mControls[i] = 0;
	}
}


ControlList::~ControlList()
{
	for(int i = 0; i < 8; ++i)
	{
		delete mControlPool[i];
	}
	//delete mControlPool;
}

void ControlList::add(Control_Type controlType)
{
	switch(controlType)
	{
	case KEYBOARD:
		mControls[mNPlayers] = mControlPool[mNKeyboards];
		mControls[mNPlayers]->setPlayer(mNPlayers+1);
		++mNPlayers;
		++mNKeyboards;
		break;
	case JOYSTICK:

		mControls[mNPlayers] = mControlPool[mNJoysticks + 4];
		mControls[mNPlayers]->setPlayer(mNPlayers+1);
		++mNPlayers;
		++mNJoysticks;
		break;
	default:
		SError("No such Device type", "Control_Type unknown!");
	};
}
void ControlList::add(sf::Keyboard::Key controlKey)
{
	switch(controlKey)
	{
	case sf::Keyboard::W:
		mControls[mNPlayers] = mControlPool[0];
		++mNPlayers;
		break;
	case sf::Keyboard::Up:
		mControls[mNPlayers] = mControlPool[1];
		++mNPlayers;
		break;
	case sf::Keyboard::I:
		mControls[mNPlayers] = mControlPool[2];
		++mNPlayers;
		break;
	case sf::Keyboard::Num8:
		mControls[mNPlayers] = mControlPool[3];
		++mNPlayers;
		break;
	default:
		break; //SError("No such control key", "value not in switch! - " + std::to_string(controlKey));
	}

}
void ControlList::update(GameData& data)
{
	for (int i = 0; i < 8; ++i)
	{
		if(mControlPool[i] != 0)
			mControlPool[i]->update(data);
	}

}

bool ControlList::isActive(Controller::Control ctrl, Player playerNumber) const
{
	switch(playerNumber)
	{
	case ANY:
		for (int i = 0; i < 8; ++i)
		{
			if(mControlPool[i]->isActive(ctrl))
				return true;;
		}
		return false;
	default:
		break;
	}
	if(mControls[playerNumber] != 0)
		return mControls[playerNumber]->isActive(ctrl);

	return false;
}

bool ControlList::isActiveReset(Controller::Control ctrl, Player playerNumber)
{
	switch(playerNumber)
	{
	case ANY:
		for (int i = 0; i < 8; ++i)
		{
			if(mControlPool[i]->isActiveReset(ctrl))
				return true;;
		}
		return false;
	default:
		break;
	}
	if(mControls[playerNumber] != 0)
		return mControls[playerNumber]->isActiveReset(ctrl);

	return false;
}

bool ControlList::isActive(Player playerNumber)
{
	return mControls[playerNumber] != 0;
}


int ControlList::getNActivePlayers() const
{
	return mNPlayers;
}

Controller& ControlList::get(int index)
{
	SAssert(mControls[index] != 0, "No controller for that index");
	return *mControls[index];
}