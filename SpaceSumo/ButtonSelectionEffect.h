#pragma once
#include "buttonobserver.h"
#include "GameData.h"
#include <ResourceManager\Animation.h>

class ButtonList;

class ButtonSelectionEffect :
	public ButtonObserver
{
public:
	ButtonSelectionEffect(int playerNumber, Button* button);
	~ButtonSelectionEffect();

	virtual void draw(RenderList& list);
	virtual void update(GameData& data, int delta,ButtonList& owner);

private:
	Animation mAnim;
	int mPlayerNumber;
	Button* mButton;
};

