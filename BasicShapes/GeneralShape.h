#ifndef BASICSHAPES_GENERALSHAPE_INCLUDED
#define BASICSHAPES_GENERALSHAPE_INCLUDED

#include "Shape.h"
/*
	A general class for Shapes to handle general intersect & envelop
*/
class GeneralShape : public Shape {
public:
	virtual ~GeneralShape(){}
	virtual float getCenterX() const = 0;
	virtual float getCenterY() const = 0;
	// true if the shape contains given PointProtocol
	virtual bool contains(const PointProtocol &point) const = 0;
	// true if this shape intersects with given shape
	virtual bool intersects(const Shape &shape) const;
	// true if this shape completely envelops given shape
	virtual bool envelops(const Shape &shape) const;
	// returns the Point closest to the given shape that's still within this shape
	virtual Point getClosestPoint(const Shape &shape) const = 0;
	// returns the Point farthest from the given shape that's still within this shape
	virtual Point getFarthestPoint(const Shape &shape) const = 0;
};

#endif