#include "stdafx.h"
#include "Face.h"
#include <ResourceManager\RHandle.h>
#include <Common\error.h>
#include "RenderList.h"
//const unsigned char Face::IDLE = 0;
//const unsigned char Face::PLEASED = 1;
//const unsigned char Face::ANGRY = 2;
//const unsigned char Face::ASHAMED = 3;

Face::Face(std::string faceImg) : mFaces(res::getTexture(faceImg + ".png"), faceImg + ".cfg", 10.f)
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

void Face::draw(RenderList &list, const sf::Vector2f &pos, bool flipped)
{
	if(flipped) 
	{
		mFaces.getSprite().setScale(-1, 1);
	}
	else
	{
		mFaces.getSprite().setScale(1, 1);
	}
	mFaces.getSprite().setPosition(pos);
	list.addSprite(mFaces);
}

FacePool::FacePool() : test("res/img/UI/test")
{

}