#include "stdafx.h"
#include "GameData.h"

GameData::GameData() : 
	gravity(0,0), 
	world(gravity), 
	input(), 
	soundlist(), 
	controlList(),
	nKeyboards(0),
	nJoysticks(0)
{
}