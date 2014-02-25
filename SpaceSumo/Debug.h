#pragma once
#include <Common\SVector.h>
#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include "RenderList.h"
#include <ResourceManager\SDrawable.h>
class Circle
	: public SDrawable, public sf::CircleShape
{
public:
	virtual float getZ()const;
	virtual void draw(sf::RenderWindow& renderWindow);
};

class Debug
{
public:
	enum Color {
		WHITE, BLACK, RED, BLUE, GREEN, YELLOW
	};
	static Debug &getS();
	void setRenderList(RenderList& renderList);
	void drawRect(float x, float y, float width, float height, Color color, float rotation = 0);
	void drawRect(SVector pos, float width, float height, Color color, float rotation = 0);
private:
	Debug();
	Debug(Debug &dB);
	~Debug();
	static Debug d;
	sf::Color mDebugColor;
	RenderList* mRenderList;
	void setColor(Color col);
};