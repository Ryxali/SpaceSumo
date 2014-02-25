#pragma once

class b2World;
class Mode;
enum Mode_Type;

#include "Command.h"

class CreateModeCommand : public Command
{
public:
	CreateModeCommand(Mode_Type mode, Mode** target, b2World &world);
	~CreateModeCommand();
	virtual void Execute();
private:
	Mode **mTarget;
	Mode_Type mMode;
	b2World &mWorld;
};

