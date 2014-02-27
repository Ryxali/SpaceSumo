#include "stdafx.h"
#include "ControlList.h"
#include "Controller.h"

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
