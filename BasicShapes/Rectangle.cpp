#include "Rectangle.h"
#include "putils.h"
#include <cassert>

Rectangle::Rectangle(float width, float height) :
	// Only a half of the sizes are stored here for performance reasons
	mHalfWidth(width/2), mHalfHeight(height/2) {
	assert(getWidth() > 0 && getHeight() > 0);
}


Rectangle::~Rectangle(void) {
	mHalfWidth = 0;
	mHalfHeight = 0;
}

bool Rectangle::contains(const PointProtocol &point) const {
	if((getCenterX()-getWidth()/2) < point.getX() && point.getX() < (getCenterX()+getWidth()/2)) {
		return ((getCenterY()-getHeight()/2) < point.getY() && point.getY() < (getCenterY()+getHeight()/2));
	}
	return false;
}

bool Rectangle::intersects(const Shape &shape) const {
	return contains(shape.getClosestPoint(*this));
}

bool Rectangle::envelops(const Shape &shape) const {
	return contains(shape.getFarthestPoint(*this));
}

Point Rectangle::getClosestPoint(const Shape &shape) const {
	if(contains(Point(shape.getCenterX(), shape.getCenterY()))) {
		return Point(shape.getCenterX(), shape.getCenterY());
	}
	Point p(Point(getCenterX(), getCenterY()));
	Point dist(shape.getCenterX()-getCenterX(), shape.getCenterY()-getCenterY());
	if(dist.getX() > mHalfWidth) {
		dist.setX(mHalfWidth);
	} else if(-mHalfWidth > dist.getX()) {
		dist.setX(mHalfWidth);
	}
	if(dist.getY() > mHalfHeight) {
		dist.setY(mHalfHeight);	
	} else if(-mHalfHeight > dist.getY()) {
		dist.setY(-mHalfHeight);
	}
	return p + dist;
}

Point Rectangle::getFarthestPoint(const Shape &shape) const {
	if(getCenterX() == shape.getCenterX() && getCenterY() == shape.getCenterY()) return Point(getCenterX()-getWidth()/2, getCenterY()-getHeight()/2);
	Point p(Point(getCenterX(), getCenterY()));
	Point dist(shape.getCenterX()-getCenterX(), shape.getCenterY()-getCenterY());

	dist.setX(-dist.getX());
	dist.setY(-dist.getY());
	if(dist.getX() > mHalfWidth) {
		dist.setX(mHalfWidth);
	} else if(-mHalfWidth > dist.getX()) {
		dist.setX(-mHalfWidth);
	}
	if(dist.getY() > mHalfHeight) {
		dist.setY(mHalfHeight);	
	} else if(-mHalfHeight > dist.getY()) {
		dist.setY(-mHalfHeight);
	}

	return p + dist;
}

float Rectangle::getWidth() const {
	return mHalfWidth + mHalfWidth;
}
float Rectangle::getHeight() const {
	return mHalfHeight + mHalfHeight;
}

void Rectangle::setWidth(float width) {
	mHalfHeight = width/2;
}
void Rectangle::setHeight(float height) {
	mHalfHeight = height/2;
}