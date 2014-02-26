#pragma once
struct SpacemanData;
#include "Command.h"
class SelectCharacterCommand : public Command
{
public:
	SelectCharacterCommand(SpacemanData &data);
	~SelectCharacterCommand();
private:
	SpacemanData &mData;
};

