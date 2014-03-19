#pragma once
#include <ResourceManager\SSprite.h>
#include <Common\SVector.h>
#include <vector>
#include "EntityImp.h"
#include "B2Body.h"
#include <Box2D\Box2D.h>

struct GameData;
struct GameStateData;
class RenderList;

class Zone
	: EntityImp
{
public:
	Zone(b2World& world);
	~Zone();
	virtual void update(GameData &data, GameStateData &gData, int delta);
	virtual void draw(RenderList& renderList);
	virtual bool isAlive();
	virtual void onCollide(Collideable* other);
	virtual void onLeave(Collideable* other);
	virtual enttype::EntityType getType();
private:
	SVector mTopLeftPos;
	SVector mSize;
	B2Body mBody;
	class Pulse
	{
	public:
		Pulse();
		void move(sf::Vector2f &pos);
		void setRotation(float degrees);
		void setPosition(sf::Vector2f pos);
		void move(float perc);
		float getPercMoved();
		sf::Vector2f getPosition();
		void draw(RenderList &list);
	private:
		Pulse(const Pulse& pulse);
		Pulse& operator=(const Pulse& pulse);

		SSprite mImg;
		float mPercPos;
	};

	class Rope
	{
	public:
		Rope(float rotation, sf::Vector2f pos, int length);
		void traverse(int delta, float factor = 1.f);
		void transfer(std::vector<Pulse*>::iterator& pulse, bool forward = true);
		void add_back(Pulse* pulse);
		void add_front(Pulse* pulse);
		void setFront(Rope* rope);
		void setBack(Rope* rope);
		void draw(RenderList &list);
		SVector end();
	private:
		Rope(const Rope& rope);
		Rope& operator=(const Rope& rope);

		std::vector<Pulse*> mPulses;
		Rope* mNext;
		Rope* mPrev;
		SSprite mImg;
		SVector mDir;
	};

	

	std::vector<Pulse*> mPulses;
	Rope mRope0;
	Rope mRope1;
	Rope mRope2;
	Rope mRope3;
};

