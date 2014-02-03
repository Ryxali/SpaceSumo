#include "SpaceManImp.h"
static int PPM = 30;


SpaceManImp::SpaceManImp(sf::Keyboard::Key up,
	sf::Keyboard::Key down,
	sf::Keyboard::Key right,
	sf::Keyboard::Key left,
	sf::Keyboard::Key attack,
	b2World& world): 
	//initlist
	mUp(up),
	mDown(down),
	mRight(right),
	mLeft(left),
	mPush(attack)
{
	//creating a rectangle to represent the collisionbox
	mShape = sf::RectangleShape(sf::Vector2f(20,20));
	mShape.setOrigin(10,10);
	mShape.setFillColor(sf::Color(255, 0, 255, 255));

	//setting up the collisionbox
	mBodyDef.position.Set(300.0f/PPM,-300.0f/PPM-n*5/PPM);
    mBodyDef.type = b2_dynamicBody;
    mBodyShape.SetAsBox(10.0f/PPM,10.0f/PPM);
    mBodyFix.shape = &mBodyShape;
    mBodyFix.density = 0.3f;
    mBodyFix.friction = 0.5f;
    mBody = world.CreateBody(&mBodyDef);
    mBody->CreateFixture(&mBodyFix);
}

SpaceManImp::~SpaceManImp()
{

}

void SpaceManImp::update()
{
	//sets the position of the rectangle-shape
	mShape.setPosition( mBody->GetPosition().x * PPM , mBody->GetPosition().y * PPM );

	//sets the rotations of the rectangleshape
	mShape.setRotation( mBody->GetAngle() );
}

void SpaceManImp::draw()
{

}

void SpaceManImp::addEffect()
{

}

sf::Shape& SpaceManImp::getShape()
{
	return mShape;
}
