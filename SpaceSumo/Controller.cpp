#include "stdafx.h"
#include "Controller.h"

bool Controller::isActive(Control ctrl) const
{
	return mStatus.at(ctrl);
}

void Controller::set(Control ctrl, bool status)
{
	mStatus.set(ctrl,status);
}