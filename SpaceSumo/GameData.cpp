#include "stdafx.h"
#include "GameData.h"

GameData::GameData() : 
	gravity(0,0), 
	world(gravity), 
	input(),
	controlList(),
	nKeyboards(0),
	nJoysticks(0)
{
}