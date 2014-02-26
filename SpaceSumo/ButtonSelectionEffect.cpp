#include "stdafx.h"
#include "Button.h"
#include "ButtonSelectionEffect.h"
#include <ResourceManager\RHandle.h>

ButtonSelectionEffect::ButtonSelectionEffect():
	mAnim(res::getTexture("res/img/test_sparkle.png"), "res/conf/anim_buttonsparkle.cfg", 10.f)
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

void ButtonSelectionEffect::update(Button& button, GameData& data, int delta)
{
	mAnim.getSprite().setPosition( button.getCenterX() , button.getCenterY() );
	
}
