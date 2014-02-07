#pragma once
#include "State.h"
#include "Entity.h"
#include <vector>
#include <iostream>



class GameState : public State {
public:
	GameState(StateList &owner, GameData& gameData);
	virtual void draw(RenderList &list);
private:
	void spacemanCreation(GameData& gameData);
	std::vector<Entity> mEntities;
};