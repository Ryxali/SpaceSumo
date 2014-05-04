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

		float r3 = mConfig.getValue<float>("minScale") + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(mConfig.getValue<float>("maxScale") - mConfig.getValue<float>("minScale"))));
		


		int direction = rand() % 4;
		switch (direction)
		{
		case 0:
			data.mEntityImpList.add(
				new Asteroid(
					b2Vec2(
						rand() % WINDOW_SIZE.x /5 ,
						rand() % WINDOW_SIZE.y /5 
					),
					b2Vec2(rand() % 1920 / PPM, - 800 / PPM), 
					data.gameData,
					r3,
					mConfig.getValue<float>("speedMultiplier")
				)
			);
			break;
		case 1:
			data.mEntityImpList.add(new Asteroid(b2Vec2(-(rand() % mConfig.getValue<int>("forwardSpeed") + mConfig.getValue<int>("forwardSpeed")), rand() % rand() % mConfig.getValue<int>("sideSpeed") - 20), b2Vec2(1920 + 800, rand() % 1080), data.gameData, r3, mConfig.getValue<float>("speedMultiplier")));
			
			break;
		case 2:			
			data.mEntityImpList.add(new Asteroid(b2Vec2(rand() % rand() % mConfig.getValue<int>("sideSpeed") - 20, -(rand() % mConfig.getValue<int>("forwardSpeed") + mConfig.getValue<int>("forwardSpeed"))), b2Vec2(rand() % 1920, 1080 + 800), data.gameData, r3, mConfig.getValue<float>("speedMultiplier")));
			
			break;
		case 3:			
			data.mEntityImpList.add(new Asteroid(b2Vec2(rand() % rand() % mConfig.getValue<int>("forwardSpeed") + mConfig.getValue<int>("forwardSpeed"), rand() % rand() % mConfig.getValue<int>("sideSpeed") - 20), b2Vec2(0 - 800, rand() % 1080), data.gameData, r3, mConfig.getValue<float>("speedMultiplier")));
			
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
	//mSoundtrack->stop();
}