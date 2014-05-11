#include "stdafx.h"
#include "CharacterSetupState.h"
#include "Button.h"
#include "ButtonMulti.h"
#include "SelectCharacterCommand.h"
#include "CharacterSelectionState.h"
#include "Characters.h"
#include "WeightSelectionState.h"
#include "AddPlayersState.h"
#include "StateList_CSelect.h"
#include "GameState.h"
#include <Common\error.h>

CharacterSetupState::CharacterSetupState(StateList &owner, StateList &menu, GameData &data, GameState &gameState, Playable* soundtrack) 
	: State(owner), StateList(), mMenuState(menu), mSpacemenData(), mGameState(gameState), mGData(data), mChars(), mSoundtrack(soundtrack)
{
	for(int i = 0; i < 4; i++)
	{
		mSpacemenData[i].spaceData = "res/conf/characters/spaceman/data_player_" + std::to_string(i+1) + ".cfg";
		mSpacemenData[i].bodyData = "res/conf/characters/spaceman/M_Body.cfg";
		mSpacemenData[i].handData = "res/conf/characters/spaceman/M_Hands.cfg";
	}
	add(new AddPlayersState(*this));
	add(new WeightSelectionState(*this, mSpacemenData, data));
	add(new CharacterSelectionState(*this, mSpacemenData));
	StateList::changeState(0);
	sync();

	/*for(auto it = chars::Character::characters.list.begin(); it != chars::Character::characters.list.end(); ++it)
	{
		mChars.add(new ButtonMulti(SVector(),
			0, 0,
			new SelectCharacterCommand(mSpacemenData[0], *it), 
			new SelectCharacterCommand(mSpacemenData[1], *it),
			new SelectCharacterCommand(mSpacemenData[2], *it),
			new SelectCharacterCommand(mSpacemenData[3], *it),
			"res/img/Test_O.png"));
	}*/
}


CharacterSetupState::~CharacterSetupState()
{
}

void CharacterSetupState::draw(RenderList &list)
{
	getCurrent().draw(list);
	//mChars.draw(list);
}

void CharacterSetupState::update(GameData &data, int delta)
{
	sync();
	getCurrent().update(data, delta);
	//mChars.update(data, delta);
}

void CharacterSetupState::changeState(st::State_Type index)
{
	switch(index)
	{
	case st::CONTROLS_SETUP_STATE:
		StateList::changeState(0);
		break;
	case st::WEIGHT_SELECT_STATE:
		StateList::changeState(2);
		break;
	case st::CHARACTER_SELECT_STATE:
		StateList::changeState(2);
		break;
	case st::FINISHED_STATE:
		mGameState.setup(mSpacemenData, mGData);
		mOwner.changeState((st::State_Type)1);
		mSoundtrack->stop();
		break;
	case st::BACK:
		mOwner.changeState((st::State_Type)2);
		mMenuState.changeState((st::State_Type)1);
		mMenuState.sync();
		break;
	default:
		SError("Unkown State", "State not in switch");
	}
}