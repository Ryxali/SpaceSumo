#pragma once
struct GameData;
struct GameStateData;
class RenderList;
class SpaceManImp;
class EntityImp;

class Wincon
{
public:
	Wincon(){}
	virtual ~Wincon(){}
	virtual void update(GameData&, GameStateData&, SpaceManImp*(&mSpacemen)[4]) = 0;
	virtual void draw(RenderList &list) = 0;
private:
	Wincon(const Wincon&);
	Wincon& operator=(const Wincon&);
};