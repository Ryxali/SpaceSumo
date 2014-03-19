#pragma once
class RenderList;

#include "Head.h"
#include "Face.h"
#include <ResourceManager\Animation.h>
#include <ResourceManager\SSprite.h>

//#include <ResourceManager\SSprite.h>
class Hud
{
public:
	Hud();
	~Hud();

	void setNPlayers(unsigned char nPlayers);
	void update(GameData&, int time, int delta);
	void draw(RenderList &list);
	Head& getHead(int index);
	float getElapsedTime();
	void setTimer(float time);
private:
	void updateClock(int time);
	unsigned char mNPlayers;
	Head mHead0;
	Head mHead1;
	Head mHead2;
	Head mHead3;
	Playable* mCurrentVoice;

	Animation mMinutes;
	Animation mTens;
	Animation mSingulars;
	SSprite mClock;

};

