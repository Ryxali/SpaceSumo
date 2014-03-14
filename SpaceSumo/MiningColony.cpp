#include "stdafx.h"
#include "MiningColony.h"
#include <ResourceManager\RHandle.h>
#include "RenderList.h"
#include "GameStateData.h"
#include "Asteroid.h"

MiningColony::MiningColony() : 
	mBackground(res::getTexture("res/img/maps/miningcolony/MiningColony_BG.png"), -1.f),
	mSoundtrack(),
	mAsteroidTimer(0)
{
	mSoundtrack.openFromFile("res/music/MiningColony/miningColony.ogg");
}

void MiningColony::update(GameStateData &data, int delta)
{
	if(mSoundtrack.getStatus() != sf::Music::Status::Playing)
	{
		//mSoundtrack.play();
	}

	if(mAsteroidTimer.isExpired())
	{
		//TODO Spawn Asteroid

		int direction = rand() % 4;
		switch (direction)
		{
		case 0:
			data.mEntityImpList.add(new Asteroid(b2Vec2(rand() % 1920 / PPM, rand() % 1080 / PPM), b2Vec2((rand() % 5 - 5),-(rand() % 5 + 3)), data.gameData));
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;

		default:
			break;
		}
		

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