#include "SpaceMan.h"
#include <SFML\Window\Keyboard.hpp>
#include <math.h>
#define PI = 3.14159265
float dotProduct(const sf::Vector2f &p) {
	return sqrt((float)(p.x * p.x+ p.y* p.y));
}

sf::Vector2f& normalize(sf::Vector2f &p) {
	float dP = dotProduct(p);
	if(dP != 0) {
		dP = 1/dP;
	}
	sf::Sprite s;
	sf::CircleShape cs;
	
	p.x = (p.x * dP);
	p.y = (p.y * dP);
	return p;
}

sf::Vector2f& rotateCounterClockwise(sf::Vector2f &p, float degrees) {
	float radian = degrees * (3.14159265f/180);
	float x = p.x;
	float y = p.y;
	float cn = cos(radian);
	float sn = sin(radian);
	p.x = x*cn - y*sn;
	p.y = x*sn + y*cn;
	return p;
}

sf::Vector2f operator/(sf::Vector2f &v0, float v) {
	return sf::Vector2f(v0.x/v, v0.y/v);
}
sf::Vector2f operator+(sf::Vector2f &v0, float v) {
	return sf::Vector2f(v0.x+v, v0.y+v);
}
sf::Vector2f operator*(sf::Vector2f &v0, float v) {
	return sf::Vector2f(v0.x*v, v0.y*v);
}

SpaceMan::SpaceMan(sf::Keyboard::Key fKey, sf::Keyboard::Key bKey, sf::Keyboard::Key rKey, sf::Keyboard::Key lKey) : forward(fKey), back(bKey), right(rKey), left(lKey) {
	

	pos.x = 100;
	pos.y = 100;
	dir.x = 1;
	dir.y = 0;
	shp.setSize(sf::Vector2f(64, 80));
	shp.setOrigin(32.f, 40.f);
	speed = sf::Vector2f(0, 0);
}


SpaceMan::~SpaceMan() {

}


void SpaceMan::render(sf::RenderWindow &win) {
	if(sf::Keyboard::isKeyPressed(right)) {
		rotateCounterClockwise(dir, 5);
		shp.rotate(5);
	}
	if(sf::Keyboard::isKeyPressed(left)) {
		rotateCounterClockwise(dir, -5);
		shp.rotate(-5);
	}
	
	if(sf::Keyboard::isKeyPressed(forward)) {
		speed =  (dotProduct(speed) <= 10) ? speed + dir : normalize(speed)*9.99;
	}
	if(sf::Keyboard::isKeyPressed(back)) {
		speed =  (dotProduct(speed) <= 10) ? speed - dir : normalize(speed)*9.99;
	}
	pos += speed;
	//sf::Vector2f shpSize = shp.getSize();
	shp.setPosition(pos);
	win.draw(shp);
}