#pragma once
#include "State.h"

class CharacterSelectionState : public State
{
public:
	CharacterSelectionState(StateList &owner);
	~CharacterSelectionState();
};

