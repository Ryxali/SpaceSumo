#include "stdafx.h"
#include "PlayerReadyToggleCommand.h"


PlayerReadyToggleCommand::PlayerReadyToggleCommand(bool &playerReadyStatus)
	: mPlayerReadyStatus(playerReadyStatus)
{
}


PlayerReadyToggleCommand::~PlayerReadyToggleCommand(void)
{
}

void PlayerReadyToggleCommand::Execute()
{
	mPlayerReadyStatus = !mPlayerReadyStatus;
}