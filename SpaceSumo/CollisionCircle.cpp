#include "CollisionCircle.h"


CollisionCircle::CollisionCircle(SVector &position, float radius, SVector &offset) : Circle(radius), mPosition(position), mOffset(offset)
{

}

float CollisionCircle::getCenterX() const
{
	return CollisionCircle::mPosition.getX();
}

float CollisionCircle::getCenterY() const
{
	return CollisionCircle::mPosition.getY();
}

SVector CollisionCircle::getOffset() const
{
	return mOffset;
}

CollisionCircle::~CollisionCircle()
{
}
