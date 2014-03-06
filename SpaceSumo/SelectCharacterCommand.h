#pragma once
struct SpacemanData;
namespace chars
{
	struct Character;
}
#include "Command.h"
class SelectCharacterCommand : public Command
{
public:
	SelectCharacterCommand(SpacemanData &data, const chars::Character &character);
	~SelectCharacterCommand();
	virtual void Execute();
private:
	SpacemanData &mData;
	const chars::Character &mChar;
};

