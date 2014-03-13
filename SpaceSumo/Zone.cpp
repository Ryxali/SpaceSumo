#include "stdafx.h"
#include "Zone.h"
#include <ResourceManager\RHandle.h>
#include <ResourceManager\STexture.h>
#include "RenderList.h"
#include <Common\ConfigReader.h>
#include "EntityType.h"

Zone::Zone(b2World& world) :
	mTopLeftPos((1920 - ConfigReader::getValue<float>("res/conf/mode/sumo/zone.cfg", "ZoneWidth"))/2, (1080 - ConfigReader::getValue<float>("res/conf/mode/sumo/zone.cfg", "ZoneHeight"))/2),
	mSize(ConfigReader::getValue<int>("res/conf/mode/sumo/zone.cfg", "ZoneWidth"), ConfigReader::getValue<int>("res/conf/mode/sumo/zone.cfg", "ZoneHeight")),
	mRope0(0, mTopLeftPos.asSfVector2f(), (int)mSize.getX()),
	mRope1(90, sf::Vector2f(mTopLeftPos.getX() + mSize.getX(), mTopLeftPos.getY()), (int)mSize.getY()),
	mRope2(180, sf::Vector2f(mTopLeftPos.getX() + mSize.getX(), mTopLeftPos.getY() + mSize.getY()), (int)mSize.getX()),
	mRope3(270, sf::Vector2f(mTopLeftPos.getX(), mTopLeftPos.getY() + mSize.getY()), (int)mSize.getY()),
	mBody(world, "res/conf/mode/sumo/zone.cfg", (float)(1920/2), (float)(1080/2)){
		
	mRope0.setBack(&mRope3);
	mRope0.setFront(&mRope1);
	mRope1.setBack(&mRope0);
	mRope1.setFront(&mRope2);
	mRope2.setBack(&mRope1);
	mRope2.setFront(&mRope3);
	mRope3.setBack(&mRope2);
	mRope3.setFront(&mRope0);
	mPulses.push_back(new Pulse());
	mRope0.add_back(mPulses[0]);
	mBody.getBody()->SetUserData(this);
}


Zone::~Zone()
{
	for (std::vector<Zone::Pulse*>::iterator it = mPulses.begin(); it != mPulses.end();)
	{
		delete *it;
		it = mPulses.erase(it);
	}
}


void Zone::update(GameData &data, GameStateData &gData, int delta)
{
	mRope0.traverse(delta);
	mRope1.traverse(delta);
	mRope2.traverse(delta);
	mRope3.traverse(delta);
}

void Zone::draw(RenderList& renderList)
{
	mRope0.draw(renderList);
	mRope1.draw(renderList);
	mRope2.draw(renderList);
	mRope3.draw(renderList);
	for(std::vector<Pulse*>::iterator it = mPulses.begin(); it != mPulses.end(); it++)
	{
		(*it)->draw(renderList);
	}
}

bool Zone::isAlive()
{
	return true;
}

EntityType Zone::getType()
{
	return ARENA;
}

Zone::Pulse::Pulse() : mImg(res::getTexture("res/img/Map_Barrier/Laser_Thick.png"), 2.f), mPercPos(0.f)
{
	mImg.getSprite().setOrigin(sf::Vector2f((float)mImg.getTexture().getSize().x/2.f, (float)mImg.getTexture().getSize().y/2.f));
}

void Zone::Pulse::move(sf::Vector2f &pos)
{
	mImg.getSprite().move(pos);
}

void Zone::Pulse::setRotation(float degrees)
{
	mImg.getSprite().setRotation(degrees);
}

void Zone::Pulse::setPosition(sf::Vector2f pos)
{
	mImg.getSprite().setPosition(pos);
}

sf::Vector2f Zone::Pulse::getPosition()
{
	return mImg.getSprite().getPosition();
}
void Zone::Pulse::move(float perc)
{
	mPercPos += perc;
}
float Zone::Pulse::getPercMoved()
{
	return mPercPos;
}
void Zone::Pulse::draw(RenderList &list)
{
	list.addSprite(mImg);
}

Zone::Rope::Rope(float rotation, sf::Vector2f pos, int length) : mImg(res::getTexture("res/img/Map_Barrier/Laser_Long.png"), 1.f), mDir(1, 0)
{
	mImg.sync();
	sf::IntRect r(0, 0, length, mImg.getTexture().getSize().y);
	mImg.getSprite().setTextureRect(r);
	//mImg.getSprite().setScale(((float)mImg.getSprite().getTexture()->getSize().x) / length.getX(), ((float)mImg.getSprite().getTexture()->getSize().y) / length.getY());
	mImg.getSprite().setOrigin(sf::Vector2f(0.f, (float)mImg.getTexture().getSize().y/2.f));
	mImg.getSprite().setPosition(pos);
	mImg.getSprite().setRotation(rotation);
	mDir.rotate(rotation);
}

void Zone::Rope::traverse(int delta, float factor)
{
	float perc = factor * (float)delta/1000.f;
	sf::Vector2f f((mDir.asSfVector2f()*factor*(float)delta)/1000.f);
	for(std::vector<Pulse*>::iterator it = mPulses.begin(); it != mPulses.end();)
	{
		(*it)->move(perc);
		if((*it)->getPercMoved() > 1)
		{
			(*it)->move(-1.f);
			transfer(it, true);
		}
		else if((*it)->getPercMoved() < 0)
		{
			(*it)->move(1.f);
			transfer(it, false);
		}
		else
		{
			(*it)->setPosition(mImg.getSprite().getPosition() + (*it)->getPercMoved() * (mDir * (float)mImg.getSprite().getTextureRect().width).asSfVector2f());
			it++;
		}
		//(*it)->setPosition(mImg.getSprite().getPosition() + (*it)->getPercMoved() * (mDir * SVector(mImg.getTexture().getSize().x, mImg.getTexture().getSize().y)).asSfVector2f());
		//it++;
	}
	
	
}

void Zone::Rope::transfer(std::vector<Pulse*>::iterator& pulse, bool forward)
{
	if(forward)
	{
		mNext->add_back(*pulse);
	}
	else
	{
		mPrev->add_front(*pulse);
	}
	pulse = mPulses.erase(pulse);
}

void Zone::Rope::add_front(Pulse* pulse)
{
	mPulses.push_back(pulse);
	pulse->setPosition(mImg.getSprite().getPosition());
	pulse->setRotation(mImg.getSprite().getRotation());
}

void Zone::Rope::add_back(Pulse* pulse)
{
	mPulses.push_back(pulse);
	pulse->setPosition(mImg.getSprite().getPosition());  
	pulse->setRotation(mImg.getSprite().getRotation());
}

void Zone::Rope::setFront(Rope* rope)
{
	mNext = rope;
}

void Zone::Rope::setBack(Rope* rope)
{
	mPrev = rope;
}

void Zone::Rope::draw(RenderList &list)
{
	list.addSprite(mImg);
}

SVector Zone::Rope::end()
{
	return mImg.getSprite().getPosition() + (mDir*(float)mImg.getTexture().getSize().x).asSfVector2f();
}