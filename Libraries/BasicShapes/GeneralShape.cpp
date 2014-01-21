#include "GeneralShape.h"
#include "putils.h"

bool GeneralShape::intersects(const Shape &shape) const {
	return contains(shape.getClosestPoint(*this));
}

bool GeneralShape::envelops(const Shape &shape) const {
	return contains(shape.getFarthestPoint(*this));
}
