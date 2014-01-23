#include "SpaceMan.h"
#include <iostream>
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

void SpaceMan::initsounds(){
	// forward sound
	if( !f_buffer.loadFromFile("jetpack.wav")){
		std::cout << "Failed to load" << std::endl;
	}
	f_sound.setBuffer(f_buffer);
	f_sound.setRelativeToListener(true);

	// back sound
	if( !b_buffer.loadFromFile("back.wav")){
		std::cout << "Failed to load" << std::endl;
	}
	b_sound.setBuffer(b_buffer);
	b_sound.setRelativeToListener(true);

	//turn sound
	if( !t_buffer.loadFromFile("turn.wav")){
		std::cout << "Failed to load" << std::endl;
	}
	t_sound.setBuffer(t_buffer);
	t_sound.setRelativeToListener(true);
}

SpaceMan::SpaceMan(sf::Keyboard::Key fKey, sf::Keyboard::Key bKey, sf::Keyboard::Key rKey, sf::Keyboard::Key lKey) : 
	forward(fKey), back(bKey), right(rKey), left(lKey), mMiddleCircle(pos, 20, SVector(0,0)), mRightCircle(pos, 15,
	SVector(1, 1)), mLeftCircle(pos, 15, SVector(1, 1)) 
{
	
	initsounds();
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

CollisionCircle SpaceMan::getMCircle()
{
	return mMiddleCircle;
}

CollisionCircle SpaceMan::getRCircle()
{
	return mRightCircle;
}

CollisionCircle SpaceMan::getLCircle()
{
	return mLeftCircle;
}

SVector SpaceMan::getSpeed() const
{
	return speed;
}

void SpaceMan::setSpeed(SVector pSpeed)
{
	speed = pSpeed;
}

void SpaceMan::render(sf::RenderWindow &win) {
	
	// shitty sound time code
	tr_time = soundclock.getElapsedTime().asMilliseconds();
	if(sf::Keyboard::isKeyPressed(right)) {
		rotateCounterClockwise(dir, 5);
		shp.rotate(5);
		if( tr_time >= 300.0f)
		{
			t_sound.play();
			soundclock.restart();
		}
	}
	tl_time = soundclock.getElapsedTime().asMilliseconds();
	if(sf::Keyboard::isKeyPressed(left)) {
		rotateCounterClockwise(dir, -5);
		shp.rotate(-5);
		if( tl_time >= 300.0f)
		{
			t_sound.play();
			soundclock.restart();
		}
	}
	
	if(sf::Keyboard::isKeyPressed(forward)) {
		speed =  (dotProduct(speed) <= 10) ? speed + dir : normalize(speed)*9.99;
		f_time = soundclock.getElapsedTime().asMilliseconds();

		if( f_time >= 330.0f)
		{
		f_sound.play();
		soundclock.restart();
		}
	}
	if(sf::Keyboard::isKeyPressed(back)) {
		speed =  (dotProduct(speed) <= 10) ? speed - dir : normalize(speed)*9.99;
		b_time = soundclock.getElapsedTime().asMilliseconds();
		
		if( b_time >= 330.0f)
		{
		
		b_sound.play();
		soundclock.restart();
		}
	}
	pos += speed;

	// sets the positions and attenuation for the sounds
	f_sound.setPosition(pos.x, pos.y, 0 );
	f_sound.setAttenuation(0.001f);

	b_sound.setPosition(pos.x, pos.y, 0 );
	b_sound.setAttenuation(0.001f);

	t_sound.setPosition(pos.x, pos.y, 0 );
	t_sound.setAttenuation(0.001f);


	//sf::Vector2f shpSize = shp.getSize();
	shp.setPosition(pos);
	win.draw(shp);
}