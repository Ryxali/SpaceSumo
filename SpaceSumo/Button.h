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
	virtual int getMapX() const;
	virtual int getMapY() const;
	virtual void setMapX(int x);
	virtual void setMapY(int y);
	virtual float getCenterX() const = 0;
	virtual float getCenterY() const = 0;
	virtual void execute(int playerNumber) = 0;

protected:
	int mMapX;
	int mMapY;
};