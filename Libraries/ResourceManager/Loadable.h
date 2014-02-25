#ifndef SPACESUMO_RESOURCEMANAGER_LOADABLE_INCLUDED
#define SPACESUMO_RESOURCEMANAGER_LOADABLE_INCLUDED
#include <string>
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