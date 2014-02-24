#pragma once
#include "Command.h"
class DualCommand : public Command
{
public:
	DualCommand(Command *comm0, Command *comm1);
	~DualCommand();
	virtual void Execute();
private:
	Command *mComm0;
	Command *mComm1;
};

