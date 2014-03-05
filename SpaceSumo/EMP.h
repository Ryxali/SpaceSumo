#pragma once
#include "PowerUp.h"
#include "B2Body.h"
#include <ResourceManager\Animation.h>
class EMP : public PowerUp
{
public:
	EMP(b2World &world, std::string bodyData, float x, float y);
	virtual void update(GameData &data, GameStateData &gData, int delta);
	virtual void draw(RenderList& renderList);
	virtual Ability* getAbility();
private:
	B2Body mBody;
	Animation mAnim;
};