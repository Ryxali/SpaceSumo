#include "stdafx.h"
#include "SetupState.h"
#include <Common\error.h>
#include <ResourceManager\RHandle.h>
#include "StateList_Setup.h"
#include "ModeSelectState.h"
#include "MapSelectState.h"
#include "GameState.h"

SetupState::SetupState(StateList &owner, GameData &data, GameState &gState, Playable* soundtrack) :
	State(owner), StateList(), mBackground(res::getTexture("res/img/UI/menu/gamesetup/background.png"), 0),
	mGState(gState), mSoundtrack(soundtrack)
{
	add(new ModeSelectState(*this, mMode, data.world));
	add(new MapSelectState(*this, mMap, data.world));
	changeState(st::MODE_SELECTION_STATE);
	sync();
}


SetupState::~SetupState()
{
}


void SetupState::draw(RenderList &list)
{
	list.addSprite(mBackground);
	for (auto it = mStates.begin(); it != mStates.end(); ++it)
	{
		(*it)->draw(list);
	}
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
	case st::FINISHED_STATE:
		mGState.setup(mMap, mMode);
		mOwner.changeState((st::State_Type)3);
		break;
	
	default:
		SError("Unknown index", "Index not in switch!");
		break;
	}
}