#include "stdafx.h"
#include "Terra.h"
#include <ResourceManager\RHandle.h>
#include "RenderList.h"

Terra::Terra():
	mBackground(res::getTexture("res/img/maps/terra/Terra_BG.png"), -1.f),
	mSoundtrack()
{
	mSoundtrack.openFromFile("res/music/terra/terra.ogg");
}

void Terra::update(GameStateData &gData, int delta)
{
	if(mSoundtrack.getStatus() != sf::Music::Status::Playing)
	{
		mSoundtrack.play();
	}
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
	mSoundtrack.stop();
}
