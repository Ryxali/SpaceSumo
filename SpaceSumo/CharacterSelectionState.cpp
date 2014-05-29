#include "stdafx.h"
#include "CharacterSelectionState.h"
#include "Characters.h"
#include "ButtonMulti.h"
#include "SelectCharacterCommand.h"
#include "ButtonSelectionEffect.h"
#include "ChangeStateCommand.h"
#include "StateList_CSelect.h"
#include "DualCommand.h"
#include "PlayerReadyToggleCommand.h"
#include <ResourceManager\RHandle.h>
CharacterSelectionState::CharacterSelectionState(StateList &owner, SpacemanData (&mSpacemenData)[4]) : State(owner), mCharacters(),
	mOnFinish(new ChangeStateCommand(st::FINISHED_STATE, owner)), mIsSetup(false), mBackground(res::getTexture("res/img/UI/menu/charSelection/background.png"), 0.0f)
{
	for(int i = 0; i < 4; ++i)
		mPlayerReadyStatus[i] = false;
	Config posCfg("res/conf/characters/face_positioning.cfg");
	SVector startPos(posCfg.getValue<int>("StartX"), posCfg.getValue<int>("StartY"));
	SVector offsetX(posCfg.getValue<int>("OffsetX"), 0);
	SVector offsetY(0, posCfg.getValue<int>("OffsetY"));
	int faceRow = posCfg.getValue<int>("facesPerRow");
	int iterations(0);
	for(auto it = chars::Character::characters.list.begin(); it != chars::Character::characters.list.end(); ++it)
	{
		Config cfg((*it).charDataRef);
		cfg.getValue<std::string>("bodyData");
		mCharacters.add(new ButtonMulti(startPos + offsetX*(iterations%faceRow) + offsetY*(iterations/faceRow), iterations%faceRow, iterations/faceRow,
			new DualCommand(
			new SelectCharacterCommand(mSpacemenData[0], (*it)),
			new PlayerReadyToggleCommand(mPlayerReadyStatus[0])),
			new DualCommand(
			new SelectCharacterCommand(mSpacemenData[1], (*it)),
			new PlayerReadyToggleCommand(mPlayerReadyStatus[1])),
			new DualCommand(
			new SelectCharacterCommand(mSpacemenData[2], (*it)),
			new PlayerReadyToggleCommand(mPlayerReadyStatus[2])),
			new DualCommand(
			new SelectCharacterCommand(mSpacemenData[3], (*it)),
			new PlayerReadyToggleCommand(mPlayerReadyStatus[3])),
			cfg.getValue<std::string>("headRef")));
		++iterations;
	}
	
}


CharacterSelectionState::~CharacterSelectionState()
{
}

void CharacterSelectionState::update(GameData& data, int delta)
{
	if(!mIsSetup)
	{
		mCharacters.clearObservers();
		switch(data.controlList.getNActivePlayers())
		{
		case 4:
			mCharacters.addObserver(new ButtonSelectionEffect(ControlList::PLAYER_4, mCharacters.getFirst(), "res/img/UI/menu/gamesetup/map_highlight"));
		case 3:
			mCharacters.addObserver(new ButtonSelectionEffect(ControlList::PLAYER_3, mCharacters.getFirst(), "res/img/UI/menu/gamesetup/map_highlight"));
		case 2:
			mCharacters.addObserver(new ButtonSelectionEffect(ControlList::PLAYER_2, mCharacters.getFirst(), "res/img/UI/menu/gamesetup/map_highlight"));
		case 1:
			mCharacters.addObserver(new ButtonSelectionEffect(ControlList::PLAYER_1, mCharacters.getFirst(), "res/img/UI/menu/gamesetup/map_highlight"));
			break;
		}
		

		mIsSetup = true;
	}
	mCharacters.update(data, delta);
	int allReady = 0;
	for(int i = 0; i < 4; ++i)
	{
		if( mPlayerReadyStatus[i]) ++allReady;
	}
	if(allReady == data.controlList.getNActivePlayers())
		mOnFinish->Execute();
}
void CharacterSelectionState::draw(RenderList& list)
{
	mCharacters.draw(list);
	list.addSprite(mBackground);
}

void CharacterSelectionState::open()
{
	for(int i = 0; i < 3; ++i)
		mPlayerReadyStatus[i] = false;
	mIsSetup = false;
}