#include "stdafx.h"
#include "DualCommand.h"


DualCommand::DualCommand(Command *comm0, Command *comm1) :
	mComm0(comm0), mComm1(comm1)
{
}


DualCommand::~DualCommand()
{
	delete mComm0;
	delete mComm1;
}

void DualCommand::Execute()
{
	mComm0->Execute();
	mComm1->Execute();
}