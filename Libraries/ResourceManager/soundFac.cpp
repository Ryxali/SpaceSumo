#include "soundFac.h"
#include "SSound.h"
#include "LoopSound.h"
#include "FinishingSound.h"
#include "UnyieldingSound.h"
#include "SoundQuene.h"
#include "RandomSound.h"
#include "SoundList.h"
#include "Music.h"
#include "Pause.h"
#include "RHandle.h"


#include <SFML\System\Thread.hpp>
#include <Common\stringH.h>
#include <vector>
#include <fstream>
#include <Common\error.h>

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void add(Playable*);
	bool mRunning;
	SoundList mSoundList;
private:
	sf::Thread mThread;
};
static SoundManager soundManager;

static void run()
{
	while(soundManager.mRunning)
	{
		soundManager.mSoundList.update();
	}

}

SoundManager::SoundManager() : mSoundList(), mThread(run), mRunning(true)
{
	mThread.launch();
}
SoundManager::~SoundManager()
{
	mRunning = false;
	mThread.wait();
}
void SoundManager::add(Playable* p)
{
	mSoundList.add(p);
}





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
				std::string f("");
				while(*it != ')')
				{
					f += *it;
					++it;
					++t;
				}
				return new SSound(res::getSoundBuffer(str::purge(f,'"')));
			}
			else if(line.substr(0, t) == "Pause")
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
				return new Pause(std::stoi(str::purge(f, ' ')));
			}
			else if(line.substr(0, t) == "LoopSound")
			{
				return new LoopSound(resolveType(line.substr(t+1)));
			}
			else if(line.substr(0, t) == "FinishingSound")
			{
				return new FinishingSound(resolveType(line.substr(t+1)));
			}
			else if(line.substr(0, t) == "UninterruptableSound" ||line.substr(0, t) == "UnyieldingSound")
			{
				return new UnyieldingSound(resolveType(line.substr(t+1)));
			}
			else if(line.substr(0, t) == "Music")
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
				return new Music(str::purge(f,'"'));
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
						int itemDpth = 0;
						while(true)
						{
							if(*it == '(')
								++itemDpth;
							if(*it == ')')
								--itemDpth;
							if(itemDpth == 0 || *(it-1) == ')')
								break;
							++it;
							++t;
						}
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
			else if(line.substr(0, t) == "RandomSound")
			{
				++it;
				RandomSound* list = new RandomSound();
				int dpth = 0;
				std::string::size_type t2 = t+1;
				while(dpth != 0 || *it != ')')
				{
					if(*it == '(')
					{
						++dpth;
						list->add(resolveType(line.substr(t2)));
						int itemDpth = 0;
						while(true)
						{
							if(*it == '(')
								++itemDpth;
							if(*it == ')')
								--itemDpth;
							if(itemDpth == 0 || *(it-1) == ')')
								break;
							++it;
							++t;
						}
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
	return 0;
}

Playable* soundFac::createSound(std::string ref)
{
	std::ifstream stream(ref);
	std::string tot = "";
	std::string line;
	while(std::getline(stream, line))
	{

		if(line.size() != 0 && (line[0] != '#'))
		{
			tot += line;
		}
	}
	SAssert(line != "", "Couldn't resolve sound data - " + ref);
	Playable* p = resolveType(tot);
	soundManager.add(p);


	return p;
}