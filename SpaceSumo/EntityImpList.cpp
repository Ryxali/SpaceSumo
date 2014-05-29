#include "stdafx.h"
#include "EntityImpList.h"


EntityImpList::EntityImpList():
	mImpList()
{
	mImpList.resize(20);
	mImpList.clear();
}


EntityImpList::~EntityImpList()
{
	for(auto it = mImpList.begin() ; it != mImpList.end(); it++ )
	{
		delete *it;
	}
}

void EntityImpList::add(EntityImp* entity)
{
	mImpList.push_back(entity);
}

void EntityImpList::update(GameData &data, GameStateData &gsData, int delta)
{
	for (auto it = mImpList.begin(); it != mImpList.end(); it++)
	{
		(*it)->update(data, gsData, delta);
	}
	
} 

void EntityImpList::draw(RenderList &renderList)
{
	for (auto it = mImpList.begin(); it != mImpList.end(); it++)
	{
		(*it)->draw(renderList);
	}
} 
void EntityImpList::clear()
{
	for (std::list<EntityImp*>::iterator it = mImpList.begin(); it != mImpList.end();)
	{
		if(*it != 0)
		{
			delete *it;
			it = mImpList.erase(it);
		}

	}
}

void EntityImpList::clean()
{
	for (std::list<EntityImp*>::iterator it = mImpList.begin(); it != mImpList.end();)
	{
		if(*it != 0)
		{
			if(!(*it)->isAlive())
			{
				delete *it;
				it = mImpList.erase(it);
			}
			else
			{
				it++;
			}
		}

	}
}