#ifndef SPACE_SUMO_LOADABLEBUNDLE_INCLUDED
#define SPACE_SUMO_LOADABLEBUNDLE_INCLUDED
#include "Loadable.h"
#include <vector>

/*
	A group of loadables
*/
class LoadableBundle : public Loadable
{
public:
	LoadableBundle();
	~LoadableBundle();
	virtual void load() final;
	virtual void unload() final;
private:
	std::vector<Loadable*> mLoadables;
};

#endif