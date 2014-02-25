#include "stdafx.h"
#include "Flag.h"


Flag::Flag(Type flagT) 
	: mFlag(flagT), mSeverity(0), mStatus(true), mExtra(0)
{
}
Flag::Flag(Type flagT, int severity, bool status, float extra) 
	: mFlag(flagT), mSeverity(severity), mStatus(status), mExtra(extra)
{
}
Flag::Flag(const Flag &f) 
	: mFlag(f.mFlag), mSeverity(f.mSeverity), mStatus(f.mStatus), mExtra(f.mExtra)
{
}