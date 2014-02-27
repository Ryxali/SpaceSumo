#include "stdafx.h"
#include "SelectCharacterCommand.h"
#include "Characters.h"

SelectCharacterCommand::SelectCharacterCommand(SpacemanData &data, chars::Character &character) : mData(data), mChar(character)
{
	chars::configure(mData, mChar);
}


SelectCharacterCommand::~SelectCharacterCommand(void)
{
	
}
