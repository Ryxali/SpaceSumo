#ifndef SPACE_SUMO_SVECTOR_INCLUDED
#define SPACE_SUMO_SVECTOR_INCLUDED

#include <SFML/System/Vector2.hpp>
#include <PointProtocol.h>

class SVector : public PointProtocol, protected sf::Vector2f
{
public:
	SVector(float x = 0, float y = 0);
	SVector(const PointProtocol &v);
	SVector(const sf::Vector2f &v);
	~SVector();
	virtual float getX() const final;
	virtual float getY() const final;
	virtual void setX(float x) final;
	virtual void setY(float Y) final;
	/*
		get the length of this vector
		returns: float - the length of this vector
	*/
	float length() const;
	/*
		normalizes this vector
		returns: SVector& - this vector in normalized form
	*/
	SVector &normalize();
	/*
		rotates this vector by given degrees clockwise
		param: float degrees - the degrees to turn this vector
		returns: SVector& - this vector in it's newly rotated form
	*/
	SVector &rotate(float degrees);


	inline SVector &operator=(SVector &v) {
		setX(v.getX());
		setY(v.getY());
		return *this;
	}
	inline SVector &operator=(PointProtocol &p) {
		setX(p.getX());
		setY(p.getY());
		return *this;
	}
	inline SVector &operator=(sf::Vector2f &v) {
		setX(v.x);
		setY(v.y);
		return *this;
	}
	inline SVector &operator+=(float v) {
		setX(getX() + v);
		setY(getY() + v);
		return *this;
	}
	inline SVector &operator+=(sf::Vector2f &v) {
		setX(getX() + v.x);
		setY(getX() + v.y);
		return *this;
	}
	inline SVector &operator-=(float v) {
		setX(getX() - v);
		setY(getY() - v);
		return *this;
	}
	inline SVector &operator-=(sf::Vector2f &v) {
		setX(getX() - v.x);
		setY(getX() - v.y);
		return *this;
	}
	inline SVector &operator*=(float v) {
		setX(getX() * v);
		setY(getY() * v);
		return *this;
	}
	inline SVector &operator*=(sf::Vector2f &v) {
		setX(getX() * v.x);
		setY(getX() * v.y);
		return *this;
	}
	inline SVector &operator/=(float v) {
		setX(getX() / v);
		setY(getY() / v);
		return *this;
	}
	inline SVector &operator/=(sf::Vector2f &v) {
		setX(getX() / v.x);
		setY(getX() / v.y);
		return *this;
	}
};

inline SVector operator/(SVector &v0, float v) {
	return SVector(v0.getX()/v, v0.getY()/v);
}
inline SVector operator/(const SVector &v0, SVector &v1) {
	return SVector(v0.getX()/v1.getX(), v0.getY()/v1.getY());
}
inline SVector operator+(const SVector &v0, float v) {
	return SVector(v0.getX()+v, v0.getY()+v);
}
inline SVector operator+(const SVector &v0, SVector &v1) {
	return SVector(v0.getX()+v1.getX(), v0.getY()+v1.getY());
}
inline SVector operator*(SVector &v0, float v) {
	return SVector(v0.getX()*v, v0.getY()*v);
}
inline SVector operator*(const SVector &v0, SVector &v1) {
	return SVector(v0.getX()*v1.getX(), v0.getY()*v1.getY());
}
inline SVector operator-(const SVector &v0, float v) {
	return SVector(v0.getX()-v, v0.getY()-v);
}
inline SVector operator-(const SVector &v0, SVector &v1) {
	return SVector(v0.getX()-v1.getX(), v0.getY()-v1.getY());
}

#endif