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

bool ControlList::add(Control_Type controlType)
{
	if(mNPlayers >= 4) return false;
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
	return true;
}

bool ControlList::toggle(Control_Type controlType)
{
	if(mNPlayers >= 4) return false;
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
	return true;
}

bool ControlList::add(sf::Keyboard::Key controlKey)
{
	if(mNPlayers >= 4) return false;
	for(int i = 0; i < 4; ++i)
	{
		if(mControlPool[i]->codeEquals(controlKey, Controller::UP))
		{
			for(int j = 0; j < 4; ++j)
			{
				if(mControls[j] == mControlPool[i])
					return false;
			}
			mControls[mNPlayers] = mControlPool[i];
			++mNPlayers;
			return true;
		}
	}
	return false;
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