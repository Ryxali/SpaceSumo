#include "Collisions.h"
#include "Debug.h"


Collisions::Collisions(SpaceMan &spaceMan1, SpaceMan &spaceMan2) : mSpaceMan1(spaceMan1), mSpaceMan2(spaceMan2)
{
	
}


Collisions::~Collisions()
{
}

void Collisions::testPlayerCollisions()
{
	if (mSpaceMan1.getLCircle().intersects(mSpaceMan2.getMCircle()) || mSpaceMan1.getRCircle().intersects(mSpaceMan2.getMCircle()))
	{
		mSpaceMan2.setSpeed(SVector(mSpaceMan2.getSpeed().getX() + (mSpaceMan2.getMCircle().getCenterX() - mSpaceMan1.getMCircle().getCenterX()) / 10, mSpaceMan2.getSpeed().getX() +  (mSpaceMan2.getMCircle().getCenterY() - mSpaceMan1.getMCircle().getCenterY()) / 10));
	}

	if (mSpaceMan2.getLCircle().intersects(mSpaceMan1.getMCircle()) || mSpaceMan2.getRCircle().intersects(mSpaceMan1.getMCircle()))
	{
		mSpaceMan1.setSpeed(SVector((mSpaceMan1.getSpeed().getX() + mSpaceMan1.getMCircle().getCenterX() - mSpaceMan2.getMCircle().getCenterX()) / 10, mSpaceMan1.getSpeed().getX() + (mSpaceMan1.getMCircle().getCenterY() - mSpaceMan2.getMCircle().getCenterY()) / 10));
	}
}