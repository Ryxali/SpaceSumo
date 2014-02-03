#include "stdafx.h"
#include "Flag.h"


Flag::Flag(Type flagT) : mFlag(flagT)
{
}
Flag::Flag(Type flagT, int severity, bool status, float extra) 
	: mFlag(flagT), mSeverity(severity), mStatus(status), mExtra(extra)
{
}
Flag::Flag(const Flag &f)
{
}