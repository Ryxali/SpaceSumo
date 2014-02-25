#include "stdafx.h"
#include "Mode.h"
Mode::Mode() : mAllowedTypes()
{

}
bool Mode::supports(Map_Type type)
{
	for(Map_Type m : mAllowedTypes)
	{
		if ( m == type )
			return true;
	}
	return false;
}

void Mode::addSupportedMapType(Map_Type mType)
{
	mAllowedTypes.push_back(mType);
}