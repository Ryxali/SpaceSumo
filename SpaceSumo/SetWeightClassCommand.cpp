#include "stdafx.h"
#include "SetWeightClassCommand.h"
#include "SpacemanData.h"

SetWeightClassCommand::SetWeightClassCommand(
	SpacemanData& mSpacemenData, std::string bodyDataRef,
	std::string handDataRef)
	: mSpacemen(mSpacemenData),
	mBodyDataRef(bodyDataRef),
	mHandDataRef(handDataRef)
{
}


SetWeightClassCommand::~SetWeightClassCommand()
{
}

void SetWeightClassCommand::Execute()
{
	mSpacemen.bodyData = mBodyDataRef;
	mSpacemen.handData = mHandDataRef;
}