#include "stdafx.h"
#include "ModeSelectState.h"
#include "DescriptedButton.h"
#include "ButtonSingle.h"
#include "Button.h"
#include "DualCommand.h"
#include "CreateModeCommand.h"
#include "ChangeStateCommand.h"
#include "StateList_Setup.h"
#include "Mode_Type.h"
#include "ButtonSelectionEffect.h"

ModeSelectState::ModeSelectState(StateList &owner, Mode *&mode, b2World &world) 
	: State(owner), mModes()
{
	Config cfg("res/img/UI/menu/gamesetup/mode_positioning.cfg");
	SVector startPos(cfg.getValue<int>("StartX"), cfg.getValue<int>("StartY"));
	SVector offset(cfg.getValue<int>("OffsetX"), cfg.getValue<int>("OffsetY"));
	int iterations(0);
	mModes.add(
		new DescriptedButton(
			new ButtonSingle(
				startPos + offset * iterations,
				0, iterations,
				new DualCommand
				(
				new CreateModeCommand(SUMO, mode, world),
				new ChangeStateCommand(st::WORLD_SELECTION_STATE, owner)
				),
				"res/img/UI/menu/gamesetup/mode_sumo",
				"res/img/UI/menu/gamesetup/mode_highlight"
			),
			"res/img/UI/menu/gamesetup/mode_sumo_desc"
		)
	);
	mModes.addObserver(new ButtonSelectionEffect(ControlList::ANY, mModes.getFirst(), "res/img/UI/menu/gamesetup/mode_highlight"));
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