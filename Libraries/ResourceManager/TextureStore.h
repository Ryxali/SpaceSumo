#pragma once
#include <map>
#include "STexture.h"

class TextureStore
{
public:
	// Constructor
	TextureStore();
	// Destructor
	~TextureStore();
	/*
		Commands the store to construct a new texture; and place it into the list.
		It will then return a reference to the object created.
		param: std::string ref - the file you want to add
		returns: Loadable& - a reference to the texture created
		usage: add("Resources/example.png");
	*/
	Loadable& add(std::string ref);
	/*
		Get a texture stored in this object.
		param: std::string ref - the file you want to get
		returns: const STexture& - a const reference to the texture requested
		usage: get("Resources/example.png");
		warning; attempting to get a non-added texture will cause an error
	*/
	const STexture& get(std::string ref) const;
private:
	TextureStore(const TextureStore &store);
	std::map<std::string, STexture> mItems;

};

