#pragma once
class EntityImp
{
public:
	virtual ~EntityImp() {}

	virtual void update() = 0;
	virtual void draw() = 0;
	// TODO add Effect to param
	virtual void afflict() = 0;
};

