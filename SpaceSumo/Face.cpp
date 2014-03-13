#include "stdafx.h"
#include "Face.h"
#include <ResourceManager\RHandle.h>
#include <Common\error.h>
#include "RenderList.h"
#include "Position.h"
//const unsigned char Face::IDLE = 0;
//const unsigned char Face::PLEASED = 1;
//const unsigned char Face::ANGRY = 2;
//const unsigned char Face::ASHAMED = 3;

Face::Face(std::string faceImg) : mFaces(res::getTexture(faceImg + ".png"), "res/img/UI/hud/face_base.cfg", 10.f)
{
}


Face::~Face(void)
{
}

void Face::changeMood(Mood mood)
{
	switch(mood)
	{
	case IDLE:
		mFaces.setCurrentRow(0);
		break;
	case PLEASED:
		mFaces.setCurrentRow(1);
		break;
	case ANGRY:
		mFaces.setCurrentRow(2);
		break;
	case ASHAMED:
		mFaces.setCurrentRow(3);
		break;
	default:
		SError("enum not found", "Unknown Mood!");
	}
}

void Face::draw(RenderList &list, const Position &pos, bool flipped)
{
	switch(pos)
	{
	case TOP_LEFT:
		mFaces.getSprite().setPosition(75, 75);
		mFaces.getSprite().setOrigin(mFaces.getSprite().getGlobalBounds().width / 2, mFaces.getSprite().getGlobalBounds().height / 2);
		mFaces.getSprite().setScale(-1, 1);
		break;
	case TOP_RIGHT:
		mFaces.getSprite().setPosition(WINDOW_SIZE.x - 75, 75);
		mFaces.getSprite().setOrigin(mFaces.getSprite().getGlobalBounds().width / 2, mFaces.getSprite().getGlobalBounds().height / 2);
		mFaces.getSprite().setScale(1, 1);
		break;
	case BOTTOM_LEFT:
		mFaces.getSprite().setPosition(75, WINDOW_SIZE.y - 75);
		mFaces.getSprite().setOrigin(mFaces.getSprite().getGlobalBounds().width / 2, mFaces.getSprite().getGlobalBounds().height / 2);
		mFaces.getSprite().setScale(-1, 1);
		break;
	case BOTTOM_RIGHT:
		mFaces.getSprite().setPosition(WINDOW_SIZE.x - 75, WINDOW_SIZE.y - 75);
		mFaces.getSprite().setOrigin(mFaces.getSprite().getGlobalBounds().width / 2, mFaces.getSprite().getGlobalBounds().height / 2);
		mFaces.getSprite().setScale(1, 1);
		break;
	}

	list.addSprite(mFaces);
}

void Face::setOrigin(int x, int y)
{
	mOrigin.x = x;
	mOrigin.y = y;
}

void Face::setSprite(std::string ref)
{
	mFaces.setSprite(ref);
}

FacePool::FacePool() : test("res/img/UI/test"), test1("res/img/UI/test"), test2("res/img/UI/test"), test3("res/img/UI/test")
{

}