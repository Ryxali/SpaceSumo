#pragma once
#include "PowerUp.h"
#include <Box2D\Box2D.h>
#include "B2Body.h"
#include <ResourceManager\Animation.h>

struct GameStateData;

class LHydrogen :
	public PowerUp
{
public:
	LHydrogen(b2World &world, std::string bodyData);
	~LHydrogen();

	virtual void update(GameData &data, GameStateData &gData, int delta);
	virtual void draw(RenderList& renderList);
	virtual Ability* getAbility();
	virtual bool isAlive();

private:
	B2Body mBody;
	Animation mAnim;
	bool mAlive;

};
