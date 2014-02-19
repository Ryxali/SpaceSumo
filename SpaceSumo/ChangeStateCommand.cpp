#include "stdafx.h"
#include "ChangeStateCommand.h"


ChangeStateCommand::ChangeStateCommand(StateList::State_Type stateType, StateList& stateList):
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
