#ifndef SPACE_SUMO_TEXTURE_INCLUDED
#define SPACE_SUMO_TEXTURE_INCLUDED

#include <SFML\Graphics\Texture.hpp>
#include "Loadable.h"
#include <string>

class STexture : public Loadable
{
public:
	STexture(std::string ref);
	~STexture();
	virtual void load() final;
	virtual void unload() final;
	const sf::Texture &getTexture() const;
	virtual const std::string& getRef() const;
	bool isLoaded() const;
	/*
		Get the current version of this Texture. The version changes each
		time the texture is loaded.
		returns: short - the current version of this Texture
	*/
	unsigned short getVersion() const;
private:
	STexture(const STexture &tex);
	sf::Texture *mTexture;
	std::string mRef;
	bool mIsLoaded;
	// Used to keep track to loads/unloads to prevent confusion amongst sprites
	unsigned short mVersion;
};

#endif