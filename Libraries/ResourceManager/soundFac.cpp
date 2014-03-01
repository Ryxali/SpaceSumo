#include "soundFac.h"
#include "SSound.h"
#include "LoopSound.h"
#include "SoundQuene.h"
#include "SoundList.h"
#include "RHandle.h"

#include <Common\stringH.h>
#include <vector>
#include <fstream>
#include <Common\error.h>

Playable* resolveType(std::string line)
{
	std::string::iterator it = line.begin();
	std::string::size_type t = 0;
	while(it != line.end())
	{
		if(*it == '(')
		{
			if(line.substr(0, t) == "Sound")
			{
				++it;
				++t;
				std::string f;
				while(*it != ')')
				{
					f += *it;
					++it;
					++t;
				}
				return new SSound(res::getSoundBuffer(str::purge(f,'"')));
			}
			else if(line.substr(0, t) == "LoopSound")
			{
				return new LoopSound(resolveType(line.substr(t+1)));
			}
			else if(line.substr(0, t) == "QueueSound")
			{
				++it;
				SoundQuene* list = new SoundQuene();
				int dpth = 0;
				std::string::size_type t2 = t+1;
				while(dpth != 0 || *it != ')')
				{
					if(*it == '(')
					{
						++dpth;
						list->add(resolveType(line.substr(t2)));
					}
					if(*it == ')')
					{
						--dpth;
					}
					if(*it == ',')
					{
						++it;
						++t;
						while(*it == ' ')
						{
							++it;
							++t;
						}
						t2 = t+1;
					}
					++it;
					++t;
				}
				return list;
			}

		}
		++t;
		++it;
	}
	SError("Couldn't resolve type!", line);
	return new SSound(res::getSoundBuffer(line));
}

Playable* soundFac::createSound(std::string ref, SoundList &list)
{
	std::ifstream stream(ref);
	std::string tot = "";
	std::string line;
	while(std::getline(stream, line))
	{
		
		if(line.size() != 0 && (line[0] != '#' && line[0] != ' '))
		{
			tot += line;
		}
	}
	SAssert(line != "", "Couldn't resolve sound data - " + ref);
	Playable* p = resolveType(tot);
	list.add(p);
	return p;
}