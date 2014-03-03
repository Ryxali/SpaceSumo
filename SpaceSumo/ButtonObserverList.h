#pragma once
#include <vector>

class ButtonObserver;
class RenderList;
struct GameData;

class ButtonObserverList
{
public:
	ButtonObserverList();
	~ButtonObserverList();

	void addObserver(ButtonObserver* observer);
	void clear();
	void update(GameData& data, int delta);
	void draw(RenderList& list);

private:
	std::vector<ButtonObserver*> mObserverList;
};

