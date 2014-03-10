#include "stdafx.h"
#include "Hud.h"
#include "RenderList.h"
#include <Common\error.h>


Hud::Hud() : mFacePool(), mUIPool(), mNPlayers(0),
	mHead0(Position::TOP_LEFT, mUIPool.TLeft, &mFacePool.test),
	mHead1(Position::TOP_RIGHT, mUIPool.TRight, &mFacePool.test1),
	mHead2(Position::BOTTOM_LEFT, mUIPool.BLeft, &mFacePool.test2),
	mHead3(Position::BOTTOM_RIGHT, mUIPool.BRight, &mFacePool.test3)
{
	
}


Hud::~Hud()
{
}

void Hud::setNPlayers(unsigned char nPlayers)
{
	mNPlayers = nPlayers;
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
}