#include "stdafx.h"
#include "Controller.h"

Controller::Controller() : mPlayerIndex(0)
{

}

bool Controller::isActive(Control ctrl) const
{
	return mStatus.at(ctrl);
}

void Controller::set(Control ctrl, bool status)
{
	mStatus.set(ctrl,status);
}

int Controller::getPlayer()
{
	return mPlayerIndex;
}

void Controller::setPlayer(int index)
{
	mPlayerIndex = index;
}