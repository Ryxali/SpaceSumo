#pragma once

class Entity
{
public:
	virtual ~Entity() {}

	virtual void update() = 0;
	virtual void movement() = 0;
	virtual void draw() = 0;

	// get & set
	virtual bool getIsAffected() = 0;
	virtual void setIsAffected(bool) = 0;

	virtual Entity* getEffect() = 0;
	virtual void setEffect(Entity* effect) = 0;

private:
	bool isAffected;
	Entity* effect;


};

