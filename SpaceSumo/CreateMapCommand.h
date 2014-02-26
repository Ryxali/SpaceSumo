#pragma once

class b2World;
class Map;
enum Map_Type;

#include "Command.h"

class CreateMapCommand : public Command
{
public:
	CreateMapCommand(Map_Type type, Map *&target, b2World &world);
	~CreateMapCommand();
	virtual void Execute();
private:
	Map *&mTarget;
	Map_Type mMap;
	b2World &mWorld;
};

