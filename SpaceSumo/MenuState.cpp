#include "stdafx.h"
#include "MenuState.h"

#include "ButtonSingle.h"
#include "Button.h"
#include <ResourceManager\RHandle.h>
#include "GameStateList.h"
#include "ChangeStateCommand.h"
#include "StateList_Main.h"
#include "ButtonSelectionEffect.h"

MenuState::MenuState(StateList &owner) : 
	State(owner),
	mBackground(res::getTexture("res/img/MenuBackground.png"), -1.f),
	mButtonList()
{
	mOwner = owner;
	mButtonList.add(new ButtonSingle(
		SVector(200,400), 
		0, 1,
		new ChangeStateCommand(st::PLAY_STATE, mOwner),
		"res/img/UI/menu/main/play",
		"res/img/UI/menu/main/selection"));
	mButtonList.addObserver(new ButtonSelectionEffect(ControlList::ANY, mButtonList.getFirst(), "res/img/UI/menu/main/selection", 2.f));
}


MenuState::~MenuState()
{

}

void MenuState::draw(RenderList &list)
{
	list.addSprite(mBackground);
	
	mButtonList.draw(list);

}

void MenuState::update(GameData &data, int delta)
{
	mButtonList.update(data, delta);
}