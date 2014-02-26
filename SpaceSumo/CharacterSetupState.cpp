#include "stdafx.h"
#include "CharacterSetupState.h"


CharacterSetupState::CharacterSetupState(StateList &owner, GameData &data, GameState &gameState) 
	: State(owner), mSpacemenData(), mGameState(gameState)
{
	for(int i = 0; i < 4; i++)
	{
		mSpacemenData[i].spaceData = "res/conf/characters/spaceman/data_player_" + std::to_string(i-1) + ".cfg";
	}
}


CharacterSetupState::~CharacterSetupState()
{
}

void CharacterSetupState::draw(RenderList &list)
{

}

void CharacterSetupState::update(GameData &data, int delta)
{

}