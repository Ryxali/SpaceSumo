#include "EffectEntity.h"

EffectEntity::~EffectEntity() 
{
	if(mParent == 0)
	{
		*mRoot = mChild;
	}
	else
	{
		if((mParent)->getType() == Entity::DECORATOR)
		{
			((EffectEntity*)(mParent))->mChild = mChild;
		}
		else
		{
			if(mParent != 0)
			{
				if(!(mParent)->getType() == Entity::DECORATOR)
				{
					mParent = mChild;
				}
			}
		}
	}
}

Entity::Type EffectEntity::getType() 
{
	return EffectEntity::DECORATOR;
}

void EffectEntity::initiate(Entity ** e)
{
	mParent = 0;
	mRoot = e;
	mChild = *e;
	*e = this;

	if((*e)->getType() == Entity::DECORATOR)
	{
		if(((EffectEntity*) *e)->mParent != 0)
		{
			mParent = *e;
		}
	}

	if((mChild)->getType() == Entity::DECORATOR)
	{
		((EffectEntity*)mChild)->mParent = this;
	}
}