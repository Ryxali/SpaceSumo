#include "stdafx.h"
#include "MiningColony.h"
#include <ResourceManager\RHandle.h>
#include "RenderList.h"
#include "GameStateData.h"
#include "Asteroid.h"
#include <ResourceManager\soundFac.h>
#include <iostream>

static Config mConfig("res/conf/maps/miningcolony/main.cfg");

MiningColony::MiningColony() : 
	mBackground(res::getTexture("res/img/maps/miningcolony/MiningColony_BG.png"), -1.f),
	mSoundtrack(soundFac::createSound("res/music/MiningColony/miningColony.spf")),
	mAsteroidTimer(0)
{

}

void MiningColony::update(GameStateData &data, int delta)
{
	//mSoundtrack->play();

	if(mAsteroidTimer.isExpired())
	{
		//TODO Spawn Asteroid
		float xSin = (((float)(std::rand()%10)) - 5.f)/10.f;
		float r3 = mConfig.getValue<float>("minScale") + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(mConfig.getValue<float>("maxScale") - mConfig.getValue<float>("minScale"))));
	
		
		float ySin = (((float)(std::rand()%10)) - 5.f)/10.f;

		data.mEntityImpList.add(
			new Asteroid(
				b2Vec2(
					(std::rand() % WINDOW_SIZE.x),
					(std::rand() % WINDOW_SIZE.y)
				),
				b2Vec2(800 ,800) , 
				data.gameData,
				r3,
				mConfig.getValue<float>("speedMultiplier")
			)
		);
	
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
	//mSoundtrack->stop();
}