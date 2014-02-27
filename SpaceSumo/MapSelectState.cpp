#include "stdafx.h"
#include "MapSelectState.h"

#include "Button.h"
#include "DualCommand.h"
#include "CreateMapCommand.h"
#include "ChangeStateCommand.h"
#include "Map_Type.h"
#include "StateList_Setup.h"

MapSelectState::MapSelectState(StateList &owner, Map *&map, b2World &world) 
	: State(owner), mMaps()
{
	mMaps.add(new Button(
		SVector(300, 300),
		new DualCommand
		(
		new CreateMapCommand(TERRA, map, world),
		new ChangeStateCommand(st::FINISHED_STATE, owner)
		),
		"res/img/UI/gamesetup/map_terra_active")
		);
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