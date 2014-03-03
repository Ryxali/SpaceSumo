#include "stdafx.h"
#include "Button.h"
#include "ButtonSelectionEffect.h"
#include <ResourceManager\RHandle.h>
#include <Common\Config.h>
#include "Controller.h"

ButtonSelectionEffect::ButtonSelectionEffect(int playerNumber, Button& button):
	mAnim(res::getTexture("res/img/test_sparkle.png"), "res/conf/anim_buttonsparkle.cfg", 10.f),
	mPlayerNumber(playerNumber),
	mButton(button)
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

void ButtonSelectionEffect::update(GameData& data, int delta)
{
	mAnim.getSprite().setPosition( mButton.getCenterX() , mButton.getCenterY() );

	if(data.controlList.isActive(Controller::Control::UP, mPlayerNumber))
	{
	}

	if(data.controlList.isActive(Controller::Control::LEFT, mPlayerNumber))
	{
	}

	if(data.controlList.isActive(Controller::Control::DOWN, mPlayerNumber))
	{
	}

	if(data.controlList.isActive(Controller::Control::RIGHT, mPlayerNumber))
	{
	}

	if(data.controlList.isActive(Controller::Control::ACTIVATE, mPlayerNumber))
	{
		mButton.execute(mPlayerNumber);
	}
}
