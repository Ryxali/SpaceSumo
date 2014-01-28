#include "SpaceMan.h"
#include <iostream>
#include <SFML\Window\Keyboard.hpp>
#include <math.h>
#include "Debug.h"
#define PI = 3.14159265


void SpaceMan::initsounds(){
	// forward sound
	if( !f_buffer.loadFromFile("Main.ogg")){
		std::cout << "Failed to load" << std::endl;
	}
	f_sound.setBuffer(f_buffer);
	f_sound.setLoop(true);
	f_sound.setRelativeToListener(true);

	//start sound
	if( !st_buffer.loadFromFile("Start.ogg"))
	{
		std::cout << "Failed to load" << std::endl;
	}
	st_sound.setBuffer(st_buffer);
	st_sound.setRelativeToListener(true);

	//stop sound
	if(!s_buffer.loadFromFile("End.ogg"))
	{
		std::cout << "Failed to load" << std::endl;
	}
	s_sound.setBuffer(s_buffer);
	s_sound.setRelativeToListener(true);
}

SpaceMan::SpaceMan(sf::Keyboard::Key fKey, sf::Keyboard::Key bKey, sf::Keyboard::Key rKey, sf::Keyboard::Key lKey) : 
	forward(fKey), back(bKey), right(rKey), left(lKey), mMiddleCircle(pos, 20, SVector(0,0)), mRightCircle(pos, 16,
	SVector(16, 20)), mLeftCircle(pos, 16, SVector(16, -20)) 
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

void SpaceMan::render(sf::RenderWindow &win, sf::Event& e) {


	if(sf::Keyboard::isKeyPressed(right)) 
	{
		rotateCounterClockwise(dir, 5);
		mRightCircle.rotate(5);
		mLeftCircle.rotate(5);
		shp.rotate(5);


	}
	if(sf::Keyboard::isKeyPressed(left)) {
		rotateCounterClockwise(dir, -5);
		mRightCircle.rotate(-5);
		mLeftCircle.rotate(-5);
		shp.rotate(-5);
	}
	
	if(sf::Keyboard::isKeyPressed(forward)) 
	{

		speed =  (dotProduct(speed) <= 10) ? speed + dir : normalize(speed)*9.99;

		if(start_press == true)
		{
			st_sound.play();
			f_sound.play();

			start_press = false;
			stop_press = true;
		}
	}

	if(!sf::Keyboard::isKeyPressed(forward))
	{
		if(stop_press == true)
		{
			s_sound.play();
			f_sound.pause();
		}

		start_press = true;
		stop_press = false;
	}

	if(sf::Keyboard::isKeyPressed(back)) 
	{
		speed =  (dotProduct(speed) <= 10) ? speed - dir : normalize(speed)*9.99;
	}

	pos += speed;

	// sets the positions and attenuation for the sounds
	f_sound.setPosition(pos.x, pos.y, 0 );
	f_sound.setAttenuation(0.001f);

	st_sound.setPosition(pos.x, pos.y, 0 );
	st_sound.setAttenuation(0.001f);

	s_sound.setPosition(pos.x, pos.y, 0 );
	s_sound.setAttenuation(0.001f);

	//sf::Vector2f shpSize = shp.getSize();
	shp.setPosition(pos);
	win.draw(shp);
	Debug::getS().drawRect(SVector(mRightCircle.getCenterX()-8, mRightCircle.getCenterY()-8), 16, 16, Debug::RED);
	Debug::getS().drawRect(SVector(mLeftCircle.getCenterX()-8, mLeftCircle.getCenterY()-8), 16, 16, Debug::GREEN);
}