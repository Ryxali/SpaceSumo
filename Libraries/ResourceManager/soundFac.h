#pragma once
class Playable;
class SoundList;

#include <string>

namespace soundFac
{
	/*
		Creates a sound using the specifications provided in ref.
		This function handles only sound specification files (.spf)
		param: ref - reference to the .spf file
		returns: Playable* - a pointer to the sound object created.
	*/
	Playable* createSound(std::string ref, SoundList &list);
}