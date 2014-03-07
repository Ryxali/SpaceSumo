#pragma once
class RenderList;

#include "Head.h"
#include "Face.h"

//#include <ResourceManager\SSprite.h>
class Hud
{
public:
	Hud();
	~Hud();

	void setNPlayers(unsigned char nPlayers);
	void draw(RenderList &list);
private:
	FacePool mFacePool;
	Head::UIPool mUIPool;
	unsigned char mNPlayers;
	Head mHead0;
	Head mHead1;
	Head mHead2;
	Head mHead3;
};

