#pragma once

class RenderList;
struct GameData;

class Button
{
public:
	Button();
	virtual ~Button();

	virtual void update(GameData &data) = 0;
	virtual void draw(RenderList &renderList) = 0;
	virtual float getCenterX() const = 0;
	virtual float getCenterY() const = 0;
	virtual void execute(int playerNumber) = 0;

private:
};