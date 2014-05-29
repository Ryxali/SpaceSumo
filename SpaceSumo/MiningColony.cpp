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
	mSoundtrack->play();

	if(mAsteroidTimer.isExpired())
	{
		//TODO Spawn Asteroid
		float xSin = (((float)(std::rand()%10)) - 5.f)/10.f;
		float r3 = mConfig.getValue<float>("minScale") + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(mConfig.getValue<float>("maxScale") - mConfig.getValue<float>("minScale"))));
	
		
		float ySin = (((float)(std::rand()%10)) - 5.f)/10.f;
		b2Vec2 pos =b2Vec2(((std::rand() % (int)WINDOW_SIZE.x)-(int)WINDOW_SIZE.x/2) , ((std::rand() % (int)WINDOW_SIZE.y)- (int)WINDOW_SIZE.y/2)); // - WINDOW_SIZE.x/2  - WINDOW_SIZE.y/2
		pos.x += pos.x < 0 ? 0 : (int)WINDOW_SIZE.x;
		pos.y += pos.y < 0 ? 0 : (int)WINDOW_SIZE.y;
		b2Vec2 tar = b2Vec2((std::rand() % WINDOW_SIZE.x * 0.8), (std::rand() % WINDOW_SIZE.y * 0.8));
		//float len = dir.Length();
		//dir.x /= len;
		//dir.y /= len;
		data.mEntityImpList.add(
			new Asteroid(
				tar,
				pos, 
				data.gameData,
				r3,
				mConfig.getValue<float>("speedMultiplier")*5
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
	mSoundtrack->stop();
}