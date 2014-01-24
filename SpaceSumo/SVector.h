#pragma once
#include <SFML/System/Vector2.hpp>
#include <BasicShapes\PointProtocol.h>
#include <math.h>
class SVector : public PointProtocol, public sf::Vector2f
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
};

inline float dotProduct(const sf::Vector2f &p) {
	return sqrt((float)(p.x * p.x+ p.y* p.y));
}

inline sf::Vector2f& normalize(sf::Vector2f &p) {
	float dP = dotProduct(p);
	if(dP != 0) {
		dP = 1/dP;
	}
	
	p.x = (p.x * dP);
	p.y = (p.y * dP);
	return p;
}

inline sf::Vector2f& rotateCounterClockwise(sf::Vector2f &p, float degrees) {
	float radian = degrees * (3.14159265f/180);
	float x = p.x;
	float y = p.y;
	float cn = cos(radian);
	float sn = sin(radian);
	p.x = x*cn - y*sn;
	p.y = x*sn + y*cn;
	return p;
}

inline sf::Vector2f operator/(sf::Vector2f &v0, float v) {
	return sf::Vector2f(v0.x/v, v0.y/v);
}
inline sf::Vector2f operator+(sf::Vector2f &v0, float v) {
	return sf::Vector2f(v0.x+v, v0.y+v);
}
inline sf::Vector2f operator*(sf::Vector2f &v0, float v) {
	return sf::Vector2f(v0.x*v, v0.y*v);
}
