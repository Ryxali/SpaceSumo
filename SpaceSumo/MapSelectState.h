#pragma once

class Map;
class b2World;

#include "State.h"
#include "Button.h"
#include <list>


class MapSelectState : public State
{
public:
	MapSelectState(StateList &owner, Map *&map, b2World &world);
	~MapSelectState();
	virtual void draw(RenderList &list);
	virtual void update(GameData &data, int delta);
private:
	std::list<Button> mMaps;
	
};

