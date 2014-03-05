#include "stdafx.h"
#include "Button.h"
#include "ButtonSelectionEffect.h"
#include <ResourceManager\RHandle.h>
#include <Common\Config.h>
#include "Controller.h"
#include <string>
#include "ButtonList.h"

ButtonSelectionEffect::ButtonSelectionEffect(int playerNumber, Button* button):
	mAnim(res::getTexture("res/img/test_sparkle.png"), "res/conf/anim_buttonsparkle.cfg", 10.f),
	mPlayerNumber(playerNumber),
	mButton(button)
{
	mAnim.getSprite().setOrigin((mAnim.getSprite().getLocalBounds().width / 2),
								 mAnim.getSprite().getLocalBounds().height / 2);
}


ButtonSelectionEffect::~ButtonSelectionEffect()
{
}

void ButtonSelectionEffect::draw(RenderList& list)
{
	list.addSprite(mAnim);
}

void ButtonSelectionEffect::update(GameData& data, int delta, ButtonList& owner)
{
	mAnim.getSprite().setPosition( mButton->getCenterX() , mButton->getCenterY() );

	if(data.controlList.isActive(Controller::Control::UP, mPlayerNumber))
	{
		mButton = owner.getUp(mButton->getMapX(), mButton->getMapY());
	}

	if(data.controlList.isActive(Controller::Control::LEFT, mPlayerNumber))
	{
		mButton = owner.getLeft(mButton->getMapX(), mButton->getMapY());
	}

	if(data.controlList.isActive(Controller::Control::DOWN, mPlayerNumber))
	{
		mButton = owner.getDown(mButton->getMapX(), mButton->getMapY());
	}

	if(data.controlList.isActive(Controller::Control::RIGHT, mPlayerNumber))
	{
		mButton = owner.getRight(mButton->getMapX(), mButton->getMapY());
	}

	if(data.controlList.isActive(Controller::Control::ACTIVATE, mPlayerNumber))
	{
		mButton->execute(mPlayerNumber);
	}
}
