#include "stdafx.h"
#include "CharacterSetupState.h"
#include "Button.h"
#include "ButtonMulti.h"
#include "SelectCharacterCommand.h"
#include "Characters.h"
CharacterSetupState::CharacterSetupState(StateList &owner, GameData &data, GameState &gameState) 
	: State(owner), mSpacemenData(), mGameState(gameState), mChars()
{
	for(int i = 0; i < 4; i++)
	{
		mSpacemenData[i].spaceData = "res/conf/characters/spaceman/data_player_" + std::to_string(i+1) + ".cfg";

	}
	for(auto it = chars::Character::characters.list.begin(); it != chars::Character::characters.list.end(); ++it)
	{
		mChars.add(new ButtonMulti(SVector(),
			new SelectCharacterCommand(mSpacemenData[0], *it), 
			new SelectCharacterCommand(mSpacemenData[1], *it),
			new SelectCharacterCommand(mSpacemenData[2], *it),
			new SelectCharacterCommand(mSpacemenData[3], *it),
			"res/img/Test_O.png"));
	}
}


CharacterSetupState::~CharacterSetupState()
{
}

void CharacterSetupState::draw(RenderList &list)
{
	mChars.draw(list);
}

void CharacterSetupState::update(GameData &data, int delta)
{
	mChars.update(data, delta);
}