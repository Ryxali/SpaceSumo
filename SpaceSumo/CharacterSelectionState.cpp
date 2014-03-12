#include "stdafx.h"
#include "CharacterSelectionState.h"
#include "Characters.h"
#include "ButtonMulti.h"
#include "SelectCharacterCommand.h"
#include "ButtonSelectionEffect.h"
CharacterSelectionState::CharacterSelectionState(StateList &owner) : State(owner), mCharacters()
{
	Config posCfg("res/conf/characters/face_positioning.cfg");
	SVector startPos(posCfg.getValue<int>("StartX"), posCfg.getValue<int>("StartY"));
	SVector offset(posCfg.getValue<int>("OffsetX"), posCfg.getValue<int>("OffsetY"));
	int iterations(0);
	for(auto it = chars::Character::characters.list.begin(); it != chars::Character::characters.list.end(); ++it)
	{
		Config cfg((*it).charDataRef);
		cfg.getValue<std::string>("bodyData");
		mCharacters.add(new ButtonMulti(startPos + offset*iterations, iterations, 0,
			new SelectCharacterCommand(mData[0], (*it)),
			new SelectCharacterCommand(mData[1], (*it)),
			new SelectCharacterCommand(mData[2], (*it)),
			new SelectCharacterCommand(mData[3], (*it)),
			cfg.getValue<std::string>("headRef")));
		++iterations;
	}
	mCharacters.addObserver(new ButtonSelectionEffect(ControlList::PLAYER_1, mCharacters.getFirst(), "res/img/UI/menu/gamesetup/map_highlight"));
}


CharacterSelectionState::~CharacterSelectionState()
{
}

void CharacterSelectionState::update(GameData& data, int delta)
{
	mCharacters.update(data, delta);
}
void CharacterSelectionState::draw(RenderList& list)
{
	mCharacters.draw(list);
}