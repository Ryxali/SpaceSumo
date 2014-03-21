#pragma once
#include "Ability.h"
#include <ResourceManager\SSprite.h>
struct GameStateData;

class EMPAbil : public Ability
{
public:

	EMPAbil(int miliseconds);
	~EMPAbil();


	virtual void activate(SVector pos, SVector dir, SVector userSpeed, GameStateData& data, b2World& world);
	virtual SSprite& getImage();
private:
	int mTimer;
	SSprite mImg;
};

