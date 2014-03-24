#pragma once
#include "SpaceJunk.h"
#include <ResourceManager\SSprite.h>
#include "B2Body.h"

class Asteroid :
	public SpaceJunk
{
public:
	Asteroid(b2Vec2 speed, b2Vec2 pos, GameData &data, float scale, float speedMulti, float rotation);
	~Asteroid();

	virtual void update(GameData &data, GameStateData &gData, int delta);
	virtual void draw(RenderList &renderList);
	virtual bool isAlive();

private:
	B2Body mBody;
	SSprite mSprite;
	b2Vec2	mSpeed;
	bool mAlive;
	float mScale;
};

