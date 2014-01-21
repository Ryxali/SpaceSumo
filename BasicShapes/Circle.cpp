#include "Circle.h"
#include "putils.h"
#include <cassert>

Circle::Circle(float radius) : mRadius(radius) {
	assert(getRadius() > 0);
}


Circle::~Circle() {
}

bool Circle::contains(const PointProtocol &point) const {
	return (mRadius * mRadius) > ((point.getX()-getCenterX())*(point.getX()-getCenterX()) + (point.getY()-getCenterY())*(point.getY()-getCenterY()));
}

bool Circle::intersects(const Circle &shape) const {
	return ((mRadius+shape.getRadius()) * (mRadius+shape.getRadius())) > ((shape.getCenterX()-getCenterX())*((shape.getCenterX()-getCenterX())) + ((shape.getCenterY()-getCenterY())*(shape.getCenterY()-getCenterY())));
}

bool Circle::intersects(const Shape &shape) const {
	return contains(shape.getClosestPoint(*this));
}

bool Circle::envelops(const Shape &shape) const {
	return contains(shape.getFarthestPoint(*this));
}

Point Circle::getClosestPoint(const Shape &shape) const {
	Point p(Point(getCenterX(), getCenterY()));
	Point dist(shape.getCenterX()-getCenterX(), shape.getCenterY()-getCenterY());
	if((dist.getX()*dist.getX()+dist.getY()*dist.getY()) < mRadius*mRadius) return Point(shape.getCenterX(), shape.getCenterY());
	p = p + (pUtils::normalize(dist) * mRadius);
	return p;
}

Point Circle::getFarthestPoint(const Shape &shape) const {
	if(getCenterX() == shape.getCenterX() && getCenterY() == shape.getCenterY()) return (Point(getCenterX()-mRadius, getCenterY()));
	return Point(getCenterX(), getCenterY()) + (pUtils::normalize(Point(shape.getCenterX(), shape.getCenterY()) - Point(getCenterX(), getCenterY())) * -mRadius);
}

float Circle::getRadius() const {
	return mRadius;
}

void Circle::setRadius(float radius) {
	assert(radius > 0);
	mRadius = radius;
}