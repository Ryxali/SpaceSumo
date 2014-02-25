#include "stdafx.h"
#include "SetupState.h"
#include <Common\error.h>
#include <ResourceManager\RHandle.h>
#include "StateList_Setup.h"
#include "ModeSelectState.h"

SetupState::SetupState(StateList &owner, GameData &data) : State(owner), StateList(), mBackground(res::getTexture("res/img/MenuBackground.png"), 0)
{
	add(new ModeSelectState(*this, &mMode, data.world));
	changeState(st::MODE_SELECTION_STATE);
	sync();
}


SetupState::~SetupState()
{
}


void SetupState::draw(RenderList &list)
{
	list.addSprite(mBackground);
	getCurrent().draw(list);
}

void SetupState::update(GameData &data, int delta)
{
	sync();
	getCurrent().update(data, delta);
}

void SetupState::changeState(st::State_Type index)
{
	switch(index)
	{
	case st::MODE_SELECTION_STATE:
		StateList::changeState(0);
		break;
	case st::WORLD_SELECTION_STATE:
		StateList::changeState(1);
		break;
	case st::OPTION_SELECTION_STATE:
		StateList::changeState(2);
		break;
	default:
		SError("Unknown index", "Index not in switch!");
		break;
	}
}