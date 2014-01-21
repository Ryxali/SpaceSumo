#ifndef BASICSHAPES_POINTPROTOCOL_INCLUDED
#define BASICSHAPES_POINTPROTOCOL_INCLUDED

class PointProtocol {
public:
	virtual ~PointProtocol(){}
	virtual float getX() const = 0;
	virtual float getY() const = 0;
	virtual void setX(float x) = 0;
	virtual void setY(float y) = 0;
};

#endif