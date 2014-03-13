#include "stdafx.h"
#include "MapSelectState.h"

#include "ButtonSingle.h"
#include "Button.h"
#include "DualCommand.h"
#include "CreateMapCommand.h"
#include "ChangeStateCommand.h"
#include "Map_Type.h"
#include "StateList_Setup.h"
#include "ButtonSelectionEffect.h"

MapSelectState::MapSelectState(StateList &owner, Map *&map, b2World &world) 
	: State(owner), mMaps()
{
	Config cfg("res/img/UI/menu/gamesetup/map_positioning.cfg");
	SVector startPos(cfg.getValue<int>("StartX"), cfg.getValue<int>("StartY"));
	SVector offset(cfg.getValue<int>("OffsetX"), cfg.getValue<int>("OffsetY"));
	int iterations(0);
	mMaps.add(new ButtonSingle(
		startPos + offset * iterations,
		0, iterations,
		new DualCommand
		(
		new CreateMapCommand(TERRA, map, world),
		new ChangeStateCommand(st::FINISHED_STATE, owner)
		),
		"res/img/UI/menu/gamesetup/map_terra",
		"res/img/UI/menu/gamesetup/map_highlight"));
	++iterations;
	mMaps.add(new ButtonSingle(
		startPos + offset * iterations,
		0, iterations,
		new DualCommand
		(
		new CreateMapCommand(TERRA, map, world),
		new ChangeStateCommand(st::FINISHED_STATE, owner)
		),
		"res/img/UI/menu/gamesetup/map_terra",
		"res/img/UI/menu/gamesetup/map_highlight"));
	mMaps.addObserver(new ButtonSelectionEffect(ControlList::ANY, mMaps.getFirst(), "res/img/UI/menu/gamesetup/map_highlight"));
}


MapSelectState::~MapSelectState()
{
	
}

void MapSelectState::draw(RenderList &list)
{
	mMaps.draw(list);
}

void MapSelectState::update(GameData &data, int delta)
{
	mMaps.update(data, delta);
}