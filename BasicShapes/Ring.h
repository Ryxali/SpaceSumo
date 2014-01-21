#ifndef BASICSHAPES_RING_INCLUDED
#define BASICSHAPES_RING_INCLUDED

#include "Circle.h"

class Ring : public Circle{
public:
	Ring(float radius, float holeRadius);
	~Ring();
	//virtual const PointProtocol& getCenter() const = 0;
	virtual float getCenterX() const = 0;
	virtual float getCenterY() const = 0;
	// true if the shape contains given point
	virtual bool contains(const PointProtocol &point) const;
	bool holeContains(const PointProtocol &point) const;
	// true if this shape intersects with given shape
	virtual bool intersects(const Shape &shape) const;
	// true if this shape completely envelops given shape
	virtual bool envelops(const Shape &shape) const;

	// returns the point closest to the given shape that's still within this shape
	virtual Point getClosestPoint(const Shape &shape) const;
	// returns the point farthest from the given shape that's still within this shape
	virtual Point getFarthestPoint(const Shape &shape) const;

	float getHoleRadius() const;
private:
	float mHoleRadius;

	
};

#endif