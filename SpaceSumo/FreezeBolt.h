#pragma once
#include "entityimp.h"
#include <Common\SVector.h>

class FreezeBolt :
	public EntityImp
{
public:
	FreezeBolt(SVector pos, SVector speed);
	~FreezeBolt();

	virtual void update(int delta);
	virtual void draw(RenderList& renderList);
	virtual void addEffect();

private:
	SVector mPosition;
	SVector mSpeed;
};

