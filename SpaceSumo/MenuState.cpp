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
	mBackground(get_addTexture("res/img/MenuBackground.png"), -1.f)
{
	
}


MenuState::~MenuState(void)
{
}

void MenuState::draw(RenderList &list)
{
	list.addSprite(mBackground);
}
