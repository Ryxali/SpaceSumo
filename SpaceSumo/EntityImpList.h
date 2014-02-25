#pragma once
#include "EntityImp.h"

class EntityImpList
{
public:
	EntityImpList();
	~EntityImpList();

	void add(EntityImp* entity);
	void update(GameData &data, GameStateData &gsData, int delta);
	void draw(RenderList &renderList);
	void clear(); 

	std::list<EntityImp*> mImpList;
};

