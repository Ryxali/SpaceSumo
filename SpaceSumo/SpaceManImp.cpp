#include "stdafx.h"
#include "SpaceManImp.h"
static int PPM = 30;
static int n = 1;

SpaceManImp::SpaceManImp(sf::Keyboard::Key up,
	sf::Keyboard::Key down,
	sf::Keyboard::Key right,
	sf::Keyboard::Key left,
	sf::Keyboard::Key push,
	b2World* world):
	mUp(up),
	mDown(down),
	mRight(right),
	mLeft(left),
	mPush(push)
{
	m_shape = sf::RectangleShape(sf::Vector2f(20,20));//(0,0,50,50,sf::Color(255,255,255));
	m_shape.setOrigin(10,10);
	m_shape.setFillColor(sf::Color::Cyan);
    m_bodyDef.position.Set(300.0f/PPM,300.0f/PPM);
    m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.linearDamping = 4.5; // air-resitance
    m_bodyShape.SetAsBox(10.0f/PPM,10.0f/PPM);
    m_bodyFix.shape = &m_bodyShape;
    m_bodyFix.density = 0.3f;
    m_bodyFix.friction = 0.5f;
    m_body = world->CreateBody(&m_bodyDef);
    m_body->CreateFixture(&m_bodyFix);
}

SpaceManImp::~SpaceManImp()
{

}

void SpaceManImp::update(int delta)
{
	if(sf::Keyboard::isKeyPressed(mUp))
	{
		m_body->ApplyForce(b2Vec2( 0 , -1 ), m_body->GetWorldCenter(), true);
	}
	if(sf::Keyboard::isKeyPressed(mDown))
	{
		m_body->ApplyForce(b2Vec2( 0 , 1 ), m_body->GetWorldCenter(), true);
	}


	// the rectangle that represents the collision box
	m_shape.setRotation( m_body->GetAngle() );
    m_shape.setPosition( m_body->GetPosition().x*PPM, m_body->GetPosition().y*PPM);
}

void SpaceManImp::draw(RenderList& renderList)
{

}

sf::RectangleShape SpaceManImp::getShape()
{
	return m_shape;
}

void SpaceManImp::addEffect()
{

}

