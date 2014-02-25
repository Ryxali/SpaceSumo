#pragma once
#include "Map_Type.h"
#include <vector>
struct GameData;
struct GameStateData;
class RenderList;
class Mode
{
public:
	Mode();
	virtual ~Mode(){}
	virtual void update(GameData &data, GameStateData &gData, int delta) = 0;
	virtual void draw(RenderList &list) = 0;
	virtual void init(GameData &data) = 0;
	bool supports(Map_Type type);
protected:
	void addSupportedMapType(Map_Type mType);
private:
	std::vector<Map_Type> mAllowedTypes;
};