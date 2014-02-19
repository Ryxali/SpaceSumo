#pragma once
#include "command.h"
#include "State.h"
#include "StateList.h"
class ChangeStateCommand :
	public Command
{
public:

	ChangeStateCommand(StateList::State_Type stateType, StateList& stateList);
	~ChangeStateCommand();
	
	virtual void Execute();

private:
	StateList::State_Type mStateType;
	StateList& mStateList;
};