#ifndef BASICSHAPES_SHAPE_INCLUDED
#define BASICSHAPES_SHAPE_INCLUDED

#include "PointProtocol.h"

// #include "putils.h" for definition
class Point;

class Shape {
public:
	virtual ~Shape(){}
	virtual float getCenterX() const = 0;
	virtual float getCenterY() const = 0;
	// true if the shape contains given PointProtocol
	virtual bool contains(const PointProtocol &point) const = 0;
	// true if this shape intersects with given shape
	virtual bool intersects(const Shape &shape) const = 0;
	// true if this shape completely envelops given shape
	virtual bool envelops(const Shape &shape) const = 0;
	// returns the Point closest to the given shape that's still within this shape
	virtual Point getClosestPoint(const Shape &shape) const = 0;
	// returns the Point farthest from the given shape that's still within this shape
	virtual Point getFarthestPoint(const Shape &shape) const = 0;
};

#endif