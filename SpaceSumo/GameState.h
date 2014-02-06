#include "RenderList.h";
#include "Entity.h";
#include <vector>;
#include <iostream>;


class GameState{
public:
	void draw(RenderList &list);
	void spacemanCreation();

private:
	std::vector<Entity> EntityList;
};