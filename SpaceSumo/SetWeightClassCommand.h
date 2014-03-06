#pragma once

struct SpacemanData;

#include "Command.h"

#include <string>

class SetWeightClassCommand : public Command
{
public:
	SetWeightClassCommand(SpacemanData& mSpacemenData, 
		std::string bodyDataRef,
		std::string handDataRef);
	~SetWeightClassCommand();
	virtual void Execute();
private:
	SpacemanData &mSpacemen;
	std::string mBodyDataRef;
	std::string mHandDataRef;
};

