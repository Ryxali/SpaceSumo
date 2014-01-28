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
	virtual void setEffect(Entity*) = 0;

protected:
	bool mIsAffected;
	Entity* mEffect;


};

