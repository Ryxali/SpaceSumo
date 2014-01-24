#include "CollisionCircle.h"


CollisionCircle::CollisionCircle(SVector &position, float radius, SVector offset) : Circle(radius), mPosition(position), mOffset(offset)
{

}
void CollisionCircle::rotate(float degrees)
{
	rotateCounterClockwise(mOffset, degrees);
}

float CollisionCircle::getCenterX() const
{
	return mPosition.getX() + mOffset.getX();
}

float CollisionCircle::getCenterY() const
{
	return CollisionCircle::mPosition.getY() + mOffset.getY();
}

SVector CollisionCircle::getOffset() const
{
	return mOffset;
}

CollisionCircle::~CollisionCircle()
{
}
