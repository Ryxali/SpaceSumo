#include "stdafx.h"
#include "Terra.h"
#include <ResourceManager\RHandle.h>
#include "RenderList.h"

Terra::Terra():
	mBackground(res::getTexture("res/img/Terra_BG.png"), -1.f)
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
	res::loadResource("res/img/Terra_BG.png");
}
