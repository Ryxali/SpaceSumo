#include "Ring.h"
#include "putils.h"
#include <cassert>

Ring::Ring(float radius, float holeRadius) : Circle(radius), mHoleRadius(holeRadius) {
	assert(getHoleRadius() > 0);
	assert(getRadius() > getHoleRadius());
}


Ring::~Ring(void) {

}

bool Ring::contains(const PointProtocol &point) const {
	if (!holeContains(point)) {
		return Circle::contains(point);
	}
	return false;
}

bool Ring::intersects(const Shape &shape) const {
	if(Circle::contains(shape.getClosestPoint(*this))) {
		return !holeContains(shape.getFarthestPoint(*this));
	}
	return false;
}

bool Ring::envelops(const Shape &shape) const {
	if(Circle::contains(shape.getFarthestPoint(*this))){
		return !holeContains(shape.getClosestPoint(*this));
	} else {
		return false;
	}
}

bool Ring::holeContains(const PointProtocol &point) const {
	return (mHoleRadius * mHoleRadius) > ((point.getX()-getCenterX())*(point.getX()-getCenterX()) + (point.getY()-getCenterY())*(point.getY()-getCenterY()));
}

Point Ring::getClosestPoint(const Shape &shape) const {
	Point p(Point(getCenterX(), getCenterY()));
	Point dist(shape.getCenterX()-getCenterX(), shape.getCenterY()-getCenterY());
	float distL = dist.getX()*dist.getX()+dist.getY()*dist.getY();
	if(distL < getRadius()*getRadius()) {
		if(distL < getHoleRadius()*getHoleRadius()) {
			return Point(shape.getCenterX()-mHoleRadius, shape.getCenterY());
		}
		return p + dist;
	}
	p = p + (pUtils::normalize(dist) * getRadius());
	return p;
}
Point Ring::getFarthestPoint(const Shape &shape) const {
	return Circle::getFarthestPoint(shape);
}

float Ring::getHoleRadius() const {
	return mHoleRadius;
}