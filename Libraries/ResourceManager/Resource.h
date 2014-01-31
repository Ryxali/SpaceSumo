#pragma once
#include <stringH.h>
#include "Loadable.h"

class Resource : public Loadable
{
public:
	Resource(std::string ref);
	~Resource();
	/*
		Causes the subclass to attempt to load the resource
		warning; causes an error if the resource fails to load
	*/
	virtual void load() final;
	/*
		Causes the subclass to unload the resource. This is assumed
		to succeed.
	*/
	virtual void unload() final;

	/*
		Loads the resource
		returns: bool - the success of the loading of resource
	*/
	virtual bool loadResource() = 0;
	/*
		Unloads the resource
	*/
	virtual void unloadResource() = 0;
	/*
		Get the file reference of this resource
		returns: const std::string& - a const reference to this resource's fileref
	*/
	virtual const std::string& getRef() const final;
	/*
		returns: bool - whether or not this resource is currently loaded
	*/
	inline bool isLoaded() const;
	/*
		Get the current version of this Texture. The version changes each
		time the texture is loaded.
		returns: short - the current version of this Texture
	*/
	unsigned short getVersion() const;
private:
	Resource(const Resource &res);

	std::string mRef;
	bool mIsLoaded;
	// Used to keep track to loads/unloads to prevent confusion amongst sprites
	unsigned short mVersion;
};

