#include "stdafx.h"
#include "Terra.h"
#include <ResourceManager\RHandle.h>
#include "RenderList.h"

Terra::Terra():
	mBackground(res::getTexture("res/img/Terra_BG.png"))
{

}

void Terra::update(GameData &data)
{

}

void Terra::draw(RenderList &list)
{
	list.addSprite(mBackground);
}

void Terra::init(GameData &data)
{
	res::addResource("res/img/Terra_BG.png");
	res::loadResource("res/img/Terra_BG.png");
}
