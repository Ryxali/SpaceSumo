#include "stdafx.h"
#include "Characters.h"
#include "SpacemanData.h"
#include <Common\Config.h>
#include <fstream>



chars::Character::CList::CList() : list()
{
	std::ifstream is;
	is.open("res/conf/characters/clist.xoxo");
	while(!is.eof())
	{
		std::string inLine;
		std::getline(is, inLine);
		list.push_back(Character(inLine));
	}
}

chars::Character::CList chars::Character::characters;


void chars::configure(SpacemanData &data, const Character &chr)
{
	Config cfg(chr.charDataRef);
	//data.bodyData = cfg.getValue<std::string>("bodyData");
	//data.handData = cfg.getValue<std::string>("handData");
	data.headRef = cfg.getValue<std::string>("headRef");
}

chars::Character::Character(std::string charDataRef)
	: charDataRef(charDataRef)
{

}

