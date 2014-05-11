#include "stdafx.h"
#include "GameStateList.h"
#include <Common\error.h>
#include "MenuState.h"
#include "GameState.h"
#include "SetupState.h"
#include "CharacterSetupState.h"
#include "HowToPlayState.h"
#include "StateList_Main.h"
#include <ResourceManager\soundFac.h>

GameStateList::GameStateList(GameData &data) : StateList()
{
	Playable* p = soundFac::createSound("res/music/menu/menu.spf");
	MenuState * mS = new MenuState(*this, p);
	add(mS);
	GameState* gS = new GameState(*this, data);
	add(gS);
	SetupState* sS = new SetupState(*this, data, *gS, p);
	add(sS);
	add(new CharacterSetupState(*this, *sS, data, *gS, p));
	add(new HowToPlayState(*this)),
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
	case st::HOW_TO_PLAY_STATE:
		StateList::changeState(4);
		break;
	default:
		SError("Unknown index", "State_Type not in switch!")
	}
}