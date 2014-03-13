#include "stdafx.h"
#include "CreateMapCommand.h"
#include "Map_Type.h"
#include <Common\error.h>
#include "Terra.h"
#include "MiningColony.h"

CreateMapCommand::CreateMapCommand(Map_Type type, Map*& target, b2World &world) :
	mMap(type), mTarget(target), mWorld(world)
{
}


CreateMapCommand::~CreateMapCommand()
{
}


void CreateMapCommand::Execute()
{
	switch(mMap)
	{
	case TERRA:
		mTarget = new Terra();
		break;
	case MINING_COLONY:
		mTarget = new MiningColony();
		break;
	default:
		SError("Unknown Map_Type", "case not in switch");
		break;
	}
}