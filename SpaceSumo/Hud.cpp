#include "stdafx.h"
#include "Hud.h"
#include "RenderList.h"
#include <Common\error.h>


Hud::Hud() : mPool(), mNPlayers(0),
	mHead0(Position::TOP_LEFT, &mPool.test),
	mHead1(Position::TOP_RIGHT, &mPool.test1),
	mHead2(Position::BOTTOM_LEFT, &mPool.test2),
	mHead3(Position::BOTTOM_RIGHT, &mPool.test3)
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