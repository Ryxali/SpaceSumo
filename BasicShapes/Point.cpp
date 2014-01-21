#include "putils.h"

Point::Point() : mX(0), mY(0) {

}

Point::Point(float x, float y) : mX(x), mY(y) {

}

Point::Point(PointProtocol &point) : mX(point.getX()), mY(point.getY()) {

}

Point::~Point() {
	mX = 0;
	mY = 0;
}

float Point::getX() const {
	return mX;
}

float Point::getY() const {
	return mY;
}

void Point::setX(float x) {
	mX = x;
}

void Point::setY(float y) {
	mY = y;
}