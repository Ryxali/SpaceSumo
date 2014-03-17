#include "stdafx.h"
#include "Hud.h"
#include "RenderList.h"
#include <Common\error.h>
#include <ResourceManager\RHandle.h>


Hud::Hud() : mNPlayers(0),
	mHead0(Position::TOP_LEFT, res::getTexture("res/img/UI/hud/cornerblue.png")),
	mHead1(Position::TOP_RIGHT, res::getTexture("res/img/UI/hud/cornerred.png")),
	mHead2(Position::BOTTOM_LEFT, res::getTexture("res/img/UI/hud/cornergreen.png")),
	mHead3(Position::BOTTOM_RIGHT, res::getTexture("res/img/UI/hud/corneryellow.png"))
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