#pragma once

class RenderList;
class Button;
struct GameData;



class ButtonList
{
public:
	ButtonList(int size = 20);
	~ButtonList();
	void add(Button* button);
	void update(GameData& data, int delta);
	void draw(RenderList& list);
	void clear();
private:
	Button** mButtons;
	int mCurSize;
	int mMaxSize;
};

