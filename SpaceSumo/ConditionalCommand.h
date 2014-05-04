#pragma once
#include "Command.h"

class ConditionalCommand :
	public Command
{
public:
	ConditionalCommand(Command& command, bool &condition);
	~ConditionalCommand();

	virtual void Execute();
private:
	bool &condition;
	Command& command;
};

