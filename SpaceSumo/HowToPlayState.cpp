#include "stdafx.h"
#include <ResourceManager\RHandle.h>
#include "HowToPlayState.h"
#include "ChangeStateCommand.h"
#include "StateList_Main.h"
#include "ButtonSingle.h"
#include <math.h>
#include "ButtonSelectionEffect.h"
#include <ResourceManager\soundFac.h>

static Config conf("res/img/UI/menu/controlAdding/positioning.cfg");

HowToPlayState::HowToPlayState(StateList &owner, Playable& p) : State(owner), mList(), mSprite(res::getTexture("res/img/UI/menu/how_to_play/bg.png"), 0), mMaintrack(p)
{
	mList.add(new ButtonSingle(SVector(conf.getValue<int>("button_prevX"), conf.getValue<int>("button_prevY")), 0, 0, new ChangeStateCommand(st::MENU_STATE, owner), "res/img/UI/menu/prev", "res/img/UI/menu/next_prev_hover"));
	mList.addObserver(new ButtonSelectionEffect(ControlList::ANY, mList.getFirst(), "res/img/UI/menu/next_prev_hover"));
	mSoundtrack = soundFac::createSound("res/music/credits/credits.spf");
}


HowToPlayState::~HowToPlayState(void)
{
	
}

void HowToPlayState::draw(RenderList &list)
{
	list.addSprite(mSprite);
	mList.draw(list);
}

void HowToPlayState::update(GameData &data, int delta)
{
	mSoundtrack->play();
	mList.update(data, delta);
}

void HowToPlayState::open()
{
	mMaintrack.stop();
}
void HowToPlayState::close()
{
	mMaintrack.play();
}