#pragma once
class EntityImp
{
public:
	EntityImp();
	~EntityImp();

	virtual void draw()=0;
	virtual void update()=0;
	virtual bool addEffect()=0; //Effect& 
};

