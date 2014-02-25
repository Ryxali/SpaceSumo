#include "stdafx.h"
#include "ChangeStateCommand.h"

ChangeStateCommand::ChangeStateCommand(st::State_Type stateType, StateList& stateList):
	mStateType(stateType),
	mStateList(stateList)
{
	
}

ChangeStateCommand::~ChangeStateCommand()
{

}

void ChangeStateCommand::Execute()
{
	mStateList.changeState(mStateType);
}
