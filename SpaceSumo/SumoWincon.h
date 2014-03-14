#pragma once
#include "Wincon.h"

class SumoWincon : public Wincon
{
public:
	SumoWincon();
	~SumoWincon();
	virtual void update(GameData&, GameStateData&, SpaceManImp*(&mSpacemen)[4]);
	virtual void draw(RenderList &list);
};

