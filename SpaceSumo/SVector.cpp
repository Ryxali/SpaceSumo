#include "SVector.h"


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