#pragma once
#include "command.h"
#include "State.h"
#include "StateList.h"
class ChangeStateCommand :
	public Command
{
public:

	ChangeStateCommand(st::State_Type stateType, StateList& stateList);
	~ChangeStateCommand();
	
	virtual void Execute();

private:
	st::State_Type mStateType;
	StateList& mStateList;
};