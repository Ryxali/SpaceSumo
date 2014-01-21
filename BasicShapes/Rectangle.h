#ifndef BASICSHAPES_RECTANGLE_INCLUDED
#define BASICSHAPES_RECTANGLE_INCLUDED

#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(float width, float height);
	~Rectangle();
	virtual float getCenterX() const = 0;
	virtual float getCenterY() const = 0;
	// true if the shape contains given PointProtocol
	virtual bool contains(const PointProtocol &point) const;
	// true if this shape intersects with given shape
	virtual bool intersects(const Shape &shape) const;
	// true if this shape completely envelops given shape
	virtual bool envelops(const Shape &shape) const;
	// returns the PointProtocol closest to the given shape that's still within this shape
	virtual Point getClosestPoint(const Shape &shape) const;
	// returns the PointProtocol farthest from the given shape that's still within this shape
	virtual Point getFarthestPoint(const Shape &shape) const;

	float getWidth() const;
	float getHeight() const;
	void setWidth(float width);
	void setHeight(float height);
private:
	float mHalfWidth, mHalfHeight;
};

#endif