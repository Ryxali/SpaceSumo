#include "stdafx.h"
#include "ModeSelectState.h"

#include "Button.h"
#include "DualCommand.h"
#include "CreateModeCommand.h"
#include "ChangeStateCommand.h"
#include "StateList_Setup.h"
#include "Mode_Type.h"
ModeSelectState::ModeSelectState(StateList &owner, Mode *&mode, b2World &world) 
	: State(owner), mModes()
{
	mModes.add(new Button(
		SVector(),
		new DualCommand
		(
		new CreateModeCommand(SUMO, mode, world),
		new ChangeStateCommand(st::WORLD_SELECTION_STATE, owner)
		),
		"res/img/UI/gamesetup/mode_sumo_active"));
}


ModeSelectState::~ModeSelectState()
{

}

void ModeSelectState::draw(RenderList &list)
{
	mModes.draw(list);
}
void ModeSelectState::update(GameData &data, int delta)
{
	mModes.update(data, delta);
}