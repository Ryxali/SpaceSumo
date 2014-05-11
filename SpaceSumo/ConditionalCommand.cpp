#include "stdafx.h"
#include "ConditionalCommand.h"


ConditionalCommand::ConditionalCommand(Command& command, bool &condition) : condition(condition), command(command)
{
}


ConditionalCommand::~ConditionalCommand()
{
}


void ConditionalCommand::Execute()
{
	if(condition)
		command.Execute();
}