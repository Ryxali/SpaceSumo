#include "stdafx.h"
#include "Hud.h"
#include "RenderList.h"
#include "GameData.h"
#include <Common\error.h>
#include <ResourceManager\RHandle.h>
#include <ResourceManager\Playable.h>
#include <iostream>

Hud::Hud() : mNPlayers(0),
	mHead0(Position::TOP_LEFT, res::getTexture("res/img/UI/hud/cornerblue.png")),
	mHead1(Position::TOP_RIGHT, res::getTexture("res/img/UI/hud/cornerred.png")),
	mHead2(Position::BOTTOM_LEFT, res::getTexture("res/img/UI/hud/cornergreen.png")),
	mHead3(Position::BOTTOM_RIGHT, res::getTexture("res/img/UI/hud/corneryellow.png")),
	mCurrentVoice(0),
	mMinutes(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/ui_numbers.cfg", 10.f),
	mTens(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/ui_numbers.cfg", 10.f),
	mSingulars(res::getTexture("res/img/UI/hud/numbers.png"), "res/img/UI/hud/ui_numbers.cfg", 10.f),
	mClock(res::getTexture("res/img/UI/hud/clock.png"), 9.f)
{
	mClock.getSprite().setOrigin(233, 0);
	mClock.getSprite().setPosition( WINDOW_SIZE.x/2, 0 );

	mMinutes.getSprite().setPosition(	(WINDOW_SIZE.x/2) - 50 , 15 );
	mTens.getSprite().setPosition(		(WINDOW_SIZE.x/2) , 15);
	mSingulars.getSprite().setPosition(	(WINDOW_SIZE.x/2) + 40 , 15);
}


Hud::~Hud()
{
}

void Hud::setNPlayers(unsigned char nPlayers)
{
	mNPlayers = nPlayers;
}

void Hud::update(GameData& data, int time, int delta)
{
	updateClock(time);

	std::vector<Playable*> mRequestedSounds;
	switch(data.controlList.getNActivePlayers())
	{
	case 4:
		mHead3.update(data, delta, mRequestedSounds);
	case 3:
		mHead2.update(data, delta, mRequestedSounds);
	case 2:
		mHead1.update(data, delta, mRequestedSounds);
	case 1:
		mHead0.update(data, delta, mRequestedSounds);
		break;
	default:
		SError("Unknown error", "Too many or too few players");
	};
	if(mRequestedSounds.size() > 0 && (mCurrentVoice == 0 || mCurrentVoice->hasEnded()))
	{
		mCurrentVoice = mRequestedSounds[0];
		mCurrentVoice->play();
	}
		
}

void Hud::draw(RenderList &list)
{
	int n = mNPlayers;
	switch(n)
	{
	case 3:
		mHead3.draw(list);
		n--;
	case 2:
		mHead2.draw(list);
		n--;
	case 1:
		mHead1.draw(list);
		n--;
	case 0:
		mHead0.draw(list);
		break;
	default:
		SError("Unknown error", "Nondescript");
	};


	list.addSprite(mClock);
	list.addSprite(mMinutes);
	list.addSprite(mTens);
	list.addSprite(mSingulars);
}

Head& Hud::getHead(int index)
{
	if(index == 0)
		return mHead0;
	if(index == 1)
		return mHead1;
	if(index == 2)
		return mHead2;
	if(index == 3)
		return mHead3;
	SError("Invalid index", "Index: [" + std::to_string(index) + "] is out of range!");
	return mHead0;
}

void Hud::updateClock(int time)
{
	
	mMinutes.setCurrentRow(time/60000);

	mTens.setCurrentRow( (time%60000)/10000);
	mSingulars.setCurrentRow(((time%60000)/1000)%10);


}
