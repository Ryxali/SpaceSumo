#include "stdafx.h"
#include "Terra.h"
#include <ResourceManager\RHandle.h>
#include "RenderList.h"
#include <ResourceManager\Playable.h>
#include <ResourceManager\soundFac.h>

Terra::Terra():
	mBackground(res::getTexture("res/img/maps/terra/Terra_BG.png"), -1.f),
	mSoundtrack(soundFac::createSound("res/music/terra/terra.spf"))
{
}

void Terra::update(GameStateData &gData, int delta)
{
	mSoundtrack->play();
}

void Terra::draw(RenderList &list)
{
	list.addSprite(mBackground);
}

void Terra::init(GameData &data)
{
	res::loadResource("res/img/maps/terra/Terra_BG.png");
}

void Terra::close()
{
	mSoundtrack->stop();
}
