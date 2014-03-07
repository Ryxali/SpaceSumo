#pragma once
#include "buttonobserver.h"
#include "GameData.h"
#include <ResourceManager\Animation.h>

class ButtonList;

class ButtonSelectionEffect :
	public ButtonObserver
{
public:
	ButtonSelectionEffect(ControlList::Player playerNumber, Button* button);
	~ButtonSelectionEffect();

	virtual void draw(RenderList& list);
	virtual void update(GameData& data, int delta,ButtonList& owner);

private:
	Animation mAnim;
	ControlList::Player mPlayerNumber;
	Button* mButton;
};