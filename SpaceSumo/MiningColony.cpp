#include "stdafx.h"
#include "MiningColony.h"
#include <ResourceManager\RHandle.h>
#include "RenderList.h"

MiningColony::MiningColony() : 
	mBackground(res::getTexture("res/img/maps/miningcolony/MiningColony_BG.png"), -1.f),
	mSoundtrack(),
	mAsteroidTimer(0)
{
	mSoundtrack.openFromFile("res/music/MiningColony/miningColony.ogg");
}

void MiningColony::update(GameData &data)
{
	if(mSoundtrack.getStatus() != sf::Music::Status::Playing)
	{
		//mSoundtrack.play();
	}

	if(mAsteroidTimer.isExpired())
	{
		//TODO Spawn Asteroid


		mAsteroidTimer.setDuration(rand() % 5000 + 3000);
		mAsteroidTimer.reset();
	}
}

void MiningColony::draw(RenderList &list)
{
	list.addSprite(mBackground);
}

void MiningColony::init(GameData &data)
{
	res::loadResource("res/img/maps/miningcolony/MiningColony_BG.png");
}

void MiningColony::close()
{
	mSoundtrack.stop();
}