#pragma once
#include "entityimp.h"
#include "Effect.h"
class Effecting :
	public EntityImp
{
public:
	~Effecting();

	virtual void update(GameData &data, GameStateData &gData, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual bool isAlive() = 0;
	virtual EntityType getType();
	virtual Effect getEffect() = 0;
};

