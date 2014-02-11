#include "stdafx.h"
#include "Zone.h"
#include <ResourceManager\RHandle.h>
#include <ResourceManager\STexture.h>
#include "RenderList.h"
Zone::Zone() :
	mRope0(0, sf::Vector2f(200, 200)),
	mRope1(90, sf::Vector2f(600, 200)),
	mRope2(180, sf::Vector2f(600, 600)),
	mRope3(270, sf::Vector2f(200, 600))
{
	mPulses.push_back(new Pulse());
	mRope0.add_back(mPulses[0]);
}


Zone::~Zone()
{
}


void Zone::update(GameData &data, GameStateData &gData, int delta)
{
	mRope0.traverse(delta, 30.f);
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

Zone::Pulse::Pulse() : mImg(res::getTexture("res/img/Map_Barrier/Laser_Thick.png"), 2.f)
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

void Zone::Pulse::draw(RenderList &list)
{
	list.addSprite(mImg);
}

Zone::Rope::Rope(float rotation, sf::Vector2f pos) : mImg(res::getTexture("res/img/Map_Barrier/Laser_Long.png"), 1.f), mDir(1, 0)
{
	mImg.getSprite().setOrigin(sf::Vector2f(0.f, (float)mImg.getTexture().getSize().y/2.f));
	mImg.getSprite().setPosition(pos);
	mImg.getSprite().setRotation(rotation);
	mDir.rotate(rotation);
}

void Zone::Rope::traverse(int delta, float factor)
{
	sf::Vector2f f((mDir.asSfVector2f()*factor*(float)delta)/1000.f);
	for(std::vector<Pulse*>::iterator it = mPulses.begin(); it != mPulses.end();)
	{
		if(!mImg.getSprite().getGlobalBounds().contains((*it)->getPosition()+f))
		{
			if(factor > 0)
			{
				transfer(it, true);
			}
			else
			{
				transfer(it, false);
			}
		}
		else
		{
			(*it)->setPosition((*it)->getPosition()+f);
			it++;
		}
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
	pulse->setPosition(mImg.getSprite().getPosition());
	pulse->setRotation(mImg.getSprite().getRotation());
}

void Zone::Rope::add_back(Pulse* pulse)
{
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