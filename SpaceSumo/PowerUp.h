#pragma once
#include "entityimp.h"
class PowerUp :
	public EntityImp
{
public:
	~PowerUp();

	virtual void update(GameData &data, int delta) = 0;
	virtual void draw(RenderList& renderList) = 0;
	virtual void addEffect();
};

