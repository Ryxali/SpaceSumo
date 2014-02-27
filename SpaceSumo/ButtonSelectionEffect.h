#pragma once
#include "buttonobserver.h"
#include "GameData.h"
#include <ResourceManager\Animation.h>

class ButtonSelectionEffect :
	public ButtonObserver
{
public:
	ButtonSelectionEffect(int playerNumber);
	~ButtonSelectionEffect();

	virtual void draw(RenderList& list);
	virtual void update(Button& button, GameData& data, int delta);

private:
	Animation mAnim;
	int mPlayerNumber;
};

