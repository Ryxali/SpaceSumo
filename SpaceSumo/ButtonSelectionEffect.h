#pragma once
#include "buttonobserver.h"
#include "GameData.h"
#include <ResourceManager\Animation.h>

class ButtonSelectionEffect :
	public ButtonObserver
{
public:
	ButtonSelectionEffect(int playerNumber, Button& button);
	~ButtonSelectionEffect();

	virtual void draw(RenderList& list);
	virtual void update(GameData& data, int delta);

private:
	Animation mAnim;
	int mPlayerNumber;
	Button& mButton;
};

