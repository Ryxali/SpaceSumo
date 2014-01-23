#pragma once
#include "SVector.h"
#include <SFML\Graphics\Color.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
class Debug
{
public:
	enum Color {
		WHITE, BLACK, RED, BLUE, GREEN, YELLOW
	};
	static Debug &getS();
	void setRenderTarget(sf::RenderWindow &win);
	void drawRect(float x, float y, float width, float height, Color color, float rotation = 0);
	void drawRect(SVector pos, float width, float height, Color color, float rotation = 0);
private:
	Debug();
	Debug(Debug &dB);
	~Debug();
	static Debug d;
	sf::Color mDebugColor;
	sf::RenderWindow *mWin;
	void setColor(Color col);
};

