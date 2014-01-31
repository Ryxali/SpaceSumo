#ifndef SPACE_SUMO_LOADABLE_INCLUDED
#define SPACE_SUMO_LOADABLE_INCLUDED
#include <stringH.h>
/*
	The loadable protocol for our resources
*/
class Loadable
{
public:
	// loads the resource
	virtual void load() = 0;
	// unloads the resource
	virtual void unload() = 0;
	/*
		returns: bool - whether or not this resource is currently loaded
	*/
	virtual const std::string& getRef() const = 0;
};

#endif