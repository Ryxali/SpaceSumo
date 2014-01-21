#ifndef BASICSHAPES_PUTILS_INCLUDED
#define BASICSHAPES_PUTILS_INCLUDED

#include <math.h>


#include "PointProtocol.h"

class Point : public PointProtocol {
public:
	Point();
	Point(float x, float y);
	Point(PointProtocol &point);
	~Point();
	virtual float getX() const;
	virtual float getY() const;
	virtual void setX(float x);
	virtual void setY(float y);
private:
	float mX, mY;
};

namespace pUtils {


	inline bool isLeftOf(const PointProtocol &p0, const PointProtocol &p1) {
		return p0.getX() < p1.getX();
	}

	inline bool isRightOf(const PointProtocol &p0, const PointProtocol &p1) {
		return p1.getX() < p1.getX();
	}

	inline bool isBelow(const PointProtocol &p0, const PointProtocol &p1) {
		return p0.getY() < p1.getY();
	}

	inline bool isAbove(const PointProtocol &p0, const PointProtocol &p1) {
		return p1.getY() < p0.getY();
	}

	inline float dotProduct(const PointProtocol &p) {
		return sqrt((float)(p.getX() * p.getX()+ p.getY()* p.getY()));
	}

	inline PointProtocol& normalize(PointProtocol &p) {
		float dP = dotProduct(p);
		if(dP != 0) {
			dP = 1/dP;
		}
		p.setX(p.getX() * dP);
		p.setY(p.getY() * dP);
		return p;
	}
}
inline Point operator-(const Point &p0, const Point &p1) {
	return Point(p0.getX() - p1.getX(), p0.getY()- p1.getY());
}
inline Point operator+(const Point &p0, const Point &p1) {
	return Point(p0.getX() + p1.getX(), p0.getY() + p1.getY());
}
inline Point operator/(const Point &p0, const Point &p1) {
	return Point(p0.getX() / p1.getX(), p0.getY() / p1.getY());
}
inline Point operator*(const Point &p, const float val) {
	return Point(p.getX() * val, p.getY() * val);
}
inline PointProtocol& operator*=(PointProtocol &p, const float v) {
	p.setX(p.getX()*v);
	p.setY(p.getY()*v);
	return p;
}
inline PointProtocol& operator+=(PointProtocol &p, const float v) {
	p.setX(p.getX()+v);
	p.setY(p.getY()+v);
	return p;
}
inline PointProtocol& operator-=(PointProtocol &p, const float v) {
	p.setX(p.getX()-v);
	p.setY(p.getY()-v);
	return p;
}

#endif