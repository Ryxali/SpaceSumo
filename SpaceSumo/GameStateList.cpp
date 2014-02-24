#include "stdafx.h"
#include "GameStateList.h"
#include <Common\error.h>
#include "MenuState.h"
#include "GameState.h"
#include "SetupState.h"
#include "StateList_Main.h"

GameStateList::GameStateList(GameData &data) : StateList()
{
	add(new MenuState(*this));
	add(new GameState(*this, data));
	add(new SetupState(*this, data));
	StateList::changeState(0);
	sync();
}


GameStateList::~GameStateList()
{
}

void GameStateList::changeState(st::State_Type index)
{
	switch(index)
	{
	case st::MENU_STATE:
		StateList::changeState(0);
		break;
	case st::GAME_STATE:
		StateList::changeState(1);
		break;
	case st::PLAY_STATE:
		StateList::changeState(2);
		break;
	default:
		SError("Unknown index", "State_Type not in switch!")
	}
}