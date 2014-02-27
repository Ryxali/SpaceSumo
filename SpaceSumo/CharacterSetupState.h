#pragma once
class GameState;
class StateList;
struct GameData;
#include "ButtonList.h"
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
	ButtonList mChars;
	SpacemanData mSpacemenData[4];
	GameState &mGameState;
};

