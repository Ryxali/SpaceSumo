#include "stdafx.h"
#include "CreateModeCommand.h"
#include "Sumo.h"
#include "Mode_Type.h"
#include <Common\error.h>

CreateModeCommand::CreateModeCommand(Mode_Type mode, Mode *&target, b2World &world) :
	mMode(mode),
	mTarget(target),
	mWorld(world)
{
}


CreateModeCommand::~CreateModeCommand()
{
}


void CreateModeCommand::Execute()
{
	switch(mMode)
	{
	case SUMO:
		mTarget = new Sumo(mWorld);
		break;
	default:
		SError("Unknown Type", "type not in switch!");
	}
}