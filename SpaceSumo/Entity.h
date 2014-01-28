#pragma once

class Entity
{
public:
	virtual ~Entity() {}

	enum Type
	{
		ENTITY, DECORATOR
	};

	virtual void update() = 0;
	virtual void movement() = 0;
	virtual void draw() = 0;

	virtual Type getType() = 0;
};

