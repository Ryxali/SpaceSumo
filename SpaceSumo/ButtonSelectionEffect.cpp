#include "stdafx.h"
#include "Button.h"
#include "ButtonSelectionEffect.h"
#include <ResourceManager\RHandle.h>
#include <Common\Config.h>
#include "Controller.h"
#include <string>
#include "ButtonList.h"

ButtonSelectionEffect::ButtonSelectionEffect(ControlList::Player playerNumber, Button* button, std::string effectRef, float z):
	mAnim(res::getTexture(effectRef+".png"), effectRef+".cfg", z),
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

	if(data.controlList.isActiveReset(Controller::Control::UP, mPlayerNumber))
	{
		mButton = owner.getUp(mButton->getMapX(), mButton->getMapY());
	}

	if(data.controlList.isActiveReset(Controller::Control::LEFT, mPlayerNumber))
	{
		mButton = owner.getLeft(mButton->getMapX(), mButton->getMapY());
	}

	if(data.controlList.isActiveReset(Controller::Control::DOWN, mPlayerNumber))
	{
		mButton = owner.getDown(mButton->getMapX(), mButton->getMapY());
	}

	if(data.controlList.isActiveReset(Controller::Control::RIGHT, mPlayerNumber))
	{
		mButton = owner.getRight(mButton->getMapX(), mButton->getMapY());
	}

	if(data.controlList.isActiveReset(Controller::Control::ENTER, mPlayerNumber))
	{
		mButton->execute(mPlayerNumber+1);
	}
}
