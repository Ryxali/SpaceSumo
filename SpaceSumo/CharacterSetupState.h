#pragma once
class GameState;
class StateList;
struct GameData;
#include "Button.h"
#include "State.h"
#include <vector>
#include "SpacemanData.h"

class CharacterSetupState : public State
{
public:
	CharacterSetupState(StateList &owner, GameData &data, GameState &gameState);
	~CharacterSetupState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
private:
	std::vector<Button> mChars;
	SpacemanData mSpacemenData[4];
	GameState &mGameState;
};

