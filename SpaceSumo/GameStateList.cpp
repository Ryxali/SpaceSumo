#include "stdafx.h"
#include "GameStateList.h"
#include <Common\error.h>
#include "MenuState.h"
#include "GameState.h"
#include "SetupState.h"
#include "CharacterSetupState.h"
#include "StateList_Main.h"
#include <ResourceManager\soundFac.h>

GameStateList::GameStateList(GameData &data) : StateList()
{
	Playable* p = soundFac::createSound("res/music/menu/menu.spf");
	add(new MenuState(*this, p));
	GameState* gS = new GameState(*this, data);
	add(gS);
	add(new SetupState(*this, data, *gS, p));
	add(new CharacterSetupState(*this, data, *gS, p));
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
	case st::C_SELECT_STATE:
		StateList::changeState(3);
		break;
	default:
		SError("Unknown index", "State_Type not in switch!")
	}
}