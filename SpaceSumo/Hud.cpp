#include "stdafx.h"
#include "Hud.h"
#include "RenderList.h"
#include <Common\error.h>


Hud::Hud() : mPool(), mNPlayers(0),
	mHead0(Head::Position::TOP_LEFT, mPool.test),
	mHead1(Head::Position::TOP_RIGHT, mPool.test),
	mHead2(Head::Position::BOTTOM_LEFT, mPool.test),
	mHead3(Head::Position::BOTTOM_RIGHT, mPool.test)
{
	
}


Hud::~Hud(void)
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