#pragma once


#include "Command.h"

class PlayerReadyToggleCommand : public Command
{
public:
	PlayerReadyToggleCommand(bool &playerReadyStatus);
	~PlayerReadyToggleCommand();

	virtual void Execute();
private:
	bool &mPlayerReadyStatus;
};

