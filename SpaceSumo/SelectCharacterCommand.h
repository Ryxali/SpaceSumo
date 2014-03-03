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
	SelectCharacterCommand(SpacemanData &data, chars::Character &character);
	~SelectCharacterCommand();
private:
	SpacemanData &mData;
	chars::Character &mChar;
};

