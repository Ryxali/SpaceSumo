#include "RenderList.h";
#include "Entity.h";
#include <vector>;
#include <iostream>;



class GameState{
public:
	GameState();
	void draw(RenderList &list);
	

private:
	void spacemanCreation();
	std::vector<Entity> mEntities;
};