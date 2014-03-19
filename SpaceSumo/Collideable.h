#pragma once
namespace enttype
{
	enum EntityType;
}

class Collideable
{
public:
	virtual void onCollide(Collideable* other) = 0;
	virtual void onLeave(Collideable* other) = 0;
	virtual enttype::EntityType getType() = 0;
};