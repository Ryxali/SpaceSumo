#include "stdafx.h"
#include "MenuState.h"

#include "ButtonSingle.h"
#include "Button.h"
#include <ResourceManager\RHandle.h>
#include "GameStateList.h"
#include "ChangeStateCommand.h"
#include "StateList_Main.h"
#include "ButtonSelectionEffect.h"
#include <ResourceManager\soundFac.h>
MenuState::MenuState(StateList &owner, Playable* soundtrack) : 
	State(owner),
	mBackground(res::getTexture("res/img/MenuBackground.png"), -1.f),
	mButtonList(), mSoundtrack(soundtrack)//soundFac::createSound("res/music/menu/menu.spf"))
{
	mOwner = owner;
	Config cfg("res/img/UI/menu/main/positioning.cfg");
	mButtonList.add(new ButtonSingle(
		SVector(cfg.getValue<int>("StartX"), cfg.getValue<int>("StartY")), 
		0, 1,
		new ChangeStateCommand(st::PLAY_STATE, mOwner),
		"res/img/UI/menu/main/play",
		"res/img/UI/menu/main/selection",
		1.f));
	mButtonList.addObserver(new ButtonSelectionEffect(ControlList::ANY, mButtonList.getFirst(), "res/img/UI/menu/main/selection", 1.f));
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
	mSoundtrack->play();
	mButtonList.update(data, delta);
}
void MenuState::close()
{

}
