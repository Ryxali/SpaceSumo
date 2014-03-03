#pragma once
#include "ButtonObserverList.h"

class RenderList;
class Button;
struct GameData;


class ButtonList
{
public:
	ButtonList(int size = 20);
	~ButtonList();
	void add(Button* button, int x, int y);
	void update(GameData& data, int delta);
	void draw(RenderList& list);
	void clear();
	Button* getUp(int x, int y);
	Button* getLeft(int x, int y);
	Button* getDown(int x, int y);
	Button* getRight(int x, int y);


private:
	Button** mButtons;
	static const int MAP_WIDTH = 20;
	static const int MAP_HEIGHT = 20;
	Button* mMap[MAP_WIDTH][MAP_HEIGHT];

	int mCurSize;
	int mMaxSize;
	ButtonObserverList mObserverList;
};

