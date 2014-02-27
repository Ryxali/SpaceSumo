#include "stdafx.h"
#include "Button.h"
#include "ButtonSelectionEffect.h"
#include <ResourceManager\RHandle.h>
#include <Common\Config.h>
#include "Controller.h"

ButtonSelectionEffect::ButtonSelectionEffect(int playerNumber):
	mAnim(res::getTexture("res/img/test_sparkle.png"), "res/conf/anim_buttonsparkle.cfg", 10.f),
	mPlayerNumber(playerNumber)
{
	mAnim.getSprite().setOrigin((mAnim.getSprite().getLocalBounds().width / 2),
								 mAnim.getSprite().getLocalBounds().height / 2);
	Config mConfig("res/img/ControlsP"+playerNumber);
}


ButtonSelectionEffect::~ButtonSelectionEffect()
{
}

void ButtonSelectionEffect::draw(RenderList& list)
{
	list.addSprite(mAnim);
}

void ButtonSelectionEffect::update(Button& button, GameData& data, int delta)
{
	mAnim.getSprite().setPosition( button.getCenterX() , button.getCenterY() );

	if(data.controlList.isActive(Controller::Control::ACTIVATE, mPlayerNumber))
	{
		button.execute(mPlayerNumber);
	}
}
