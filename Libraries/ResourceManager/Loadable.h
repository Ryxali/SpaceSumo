#ifndef SPACE_SUMO_LOADABLE_INCLUDED
#define SPACE_SUMO_LOADABLE_INCLUDED
#include <string>
/*
	The loadable protocol for our resources
*/
class Loadable
{
public:
	virtual void load() = 0;
	virtual void unload() = 0;
	virtual const std::string& getRef() const = 0;
};

#endif