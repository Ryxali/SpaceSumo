#include "stdafx.h"
#include "ControlList.h"
#include "Controller.h"
#include <Common\error.h>
ControlList::ControlList()
{
}


ControlList::~ControlList()
{
}

void ControlList::add(Controller* controller)
{
	mControls.push_back(controller);
}

void ControlList::update(GameData& data)
{
	for (auto it = mControls.begin(); it != mControls.end(); it++ )
	{
		(*it)->update(data);
	}

}

bool ControlList::isActive(Controller::Control ctrl, int playerNumber) const
{
	for (auto it = mControls.begin(); it != mControls.end(); it++ )
	{
		if(playerNumber == (*it)->getPlayer())
			return (*it)->isActive(ctrl);
	}
	return false;
}

bool ControlList::isActiveReset(Controller::Control ctrl, int playerNumber)
{
	for (auto it = mControls.begin(); it != mControls.end(); it++ )
	{
		if(playerNumber == (*it)->getPlayer())
		{
			return (*it)->isActiveReset(ctrl);
			
		}
	}
	return false;
}

Controller& ControlList::get(int index)
{
	for ( auto it = mControls.begin(); it != mControls.end(); ++it)
	{
		if(index == (*it)->getPlayer())
			return **it;
	}
	SError("No such index", "Player not found!");
}