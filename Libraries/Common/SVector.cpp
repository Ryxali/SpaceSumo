#include "stdafx.h"
#include "SVector.h"
#include <math.h>

SVector::SVector(float x, float y) : sf::Vector2f(x, y)
{

}
SVector::SVector(const PointProtocol &v)  : sf::Vector2f(v.getX(), v.getY())
{

}
SVector::SVector(const sf::Vector2f &v) : sf::Vector2f(v.x, v.y)
{

}
SVector::~SVector()
{
	x = 0;
	y = 0;
}

sf::Vector2f &SVector::asSfVector2f()
{
	return *this;
}
b2Vec2 SVector::cloneB2f()
{
	return b2Vec2(x, y);
}
sf::Vector2f SVector::cloneV2f()
{
	return sf::Vector2f(x, y);
}

float SVector::getX() const
{
	return x;
}
float SVector::getY() const
{
	return y;
}
void SVector::setX(float x) 
{
	this -> x = x;
}
void SVector::setY(float Y) 
{
	this -> x = x;
}

float SVector::length() const {
	return sqrt((float)(getX() * getX() + getY() * getY()));
}

SVector &SVector::normalize() {
	float dP = length();
	if(dP != 0) {
		dP = 1/dP;
	}
	setX(getX() * dP);
	setY(getY() * dP);
	return *this;
}

SVector &SVector::rotate(float degrees) {
	float radian = degrees * (3.14159265f/180);
	float x = getX();
	float y = getY();
	float cn = cos(radian);
	float sn = sin(radian);
	setX(getX() * cn - getY() * sn);
	setY(getX() * sn + getY() * cn);
	return *this;
}