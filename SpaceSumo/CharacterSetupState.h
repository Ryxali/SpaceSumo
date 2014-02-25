#pragma once

class StateList;
struct GameData;
#include "Button.h"
#include "State.h"
#include <vector>

class CharacterSetupState : public State
{
public:
	CharacterSetupState(StateList &owner, GameData &data);
	~CharacterSetupState();
private:
	std::vector<Button> mChars;
};

