#pragma once
#include "SVector.h"
#include <BasicShapes\Circle.h>
class CollisionCircle : public Circle
{
public:
	CollisionCircle(SVector &position, float radius, SVector &offset);
	virtual float getCenterX() const;
	virtual float getCenterY() const;
	~CollisionCircle();
	SVector getOffset() const;

private:
	SVector &mPosition;
	SVector &mOffset;
};