#pragma once
class Playable;
class GameState;
class StateList;
struct GameData;
#include "ButtonList.h"
#include "State.h"
#include "StateList.h"
#include <vector>
#include "SpacemanData.h"

class CharacterSetupState : public State , public StateList
{
public:
	CharacterSetupState(StateList &owner, StateList &menu, GameData &data, GameState &gameState, Playable*);
	~CharacterSetupState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
	virtual void changeState(st::State_Type index);
private:
	StateList& mMenuState;
	ButtonList mChars;
	SpacemanData mSpacemenData[4];
	GameState &mGameState;
	GameData &mGData;
	Playable* mSoundtrack;
};

