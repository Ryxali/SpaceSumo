#include "stdafx.h"
#include "SelectCharacterCommand.h"
#include "Characters.h"

SelectCharacterCommand::SelectCharacterCommand(SpacemanData &data, const chars::Character &character) : mData(data), mChar(character)
{
	
}


SelectCharacterCommand::~SelectCharacterCommand()
{
	
}

void SelectCharacterCommand::Execute()
{
	chars::configure(mData, mChar);
}
