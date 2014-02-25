#include "stdafx.h"
#include "MenuState.h"
#include <ResourceManager\RHandle.h>


static const STexture& get_addTexture(std::string ref)
{
	res::addResource(ref);
	res::loadResource(ref);
	return res::getTexture(ref);
}

MenuState::MenuState(StateList &owner) : 
	State(owner),
	mBackground(get_addTexture("res/img/MenuBackground.png")),
	mHighlight(get_addTexture("res/img/MenuHighlight.png")),
	mGlitter(get_addTexture("res/img/MenuGlitter.png"))
{

}


MenuState::~MenuState(void)
{
}

void MenuState::draw(RenderList &list)
{
	if (button1.mHovered){
		list.addSprite(mHighlight);
		list.addSprite(mGlitter);
	}
	list.addSprite(mBackground);
}
