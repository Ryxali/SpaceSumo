#pragma once
#include <map>
#include "SSoundBuffer.h"
class SoundBufferStore
{
public:
	// Constructor
	SoundBufferStore();
	// Destructor
	~SoundBufferStore();
	/*
		Commands the store to construct a new sound buffer; and place it into the list.
		It will then return a reference to the object created.
		param: std::string ref - the file you want to add
		returns: Loadable& - a reference to the sound buffer created
		usage: add("Resources/example.ogg");
	*/
	Loadable& add(std::string ref);
	/*
		Get a sound buffer stored in this object.
		param: std::string ref - the file you want to get
		returns: const SSoundBuffer& - a const reference to the sound buffer requested
		usage: get("Resources/example.ogg");
		warning; attempting to get a non-added sound buffer will cause an error
	*/
	const SSoundBuffer& get(std::string ref) const;
private:
	SoundBufferStore(const SoundBufferStore &store);
	std::map<std::string, SSoundBuffer> mItems;
};

