#pragma once
#include "entityimp.h"

enum EntityType;
struct GameStateData;

class Ability;

class PowerUp :
	public EntityImp
{
public:
	~PowerUp();

	virtual void update(GameData &data, GameStateData &gData, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual void addEffect();
	virtual Ability* getAbility() = 0;
	virtual EntityType getType();

protected:
	Ability* mAbility;
};
