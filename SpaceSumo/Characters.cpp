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
		std::string inLine2;
		std::getline(is, inLine2);
		list.push_back(Character(inLine, inLine2));
	}
}

chars::Character::CList chars::Character::characters;


void chars::configure(SpacemanData &data, const Character &chr)
{
	Config cfg(chr.charDataRef);
	//data.bodyData = cfg.getValue<std::string>("bodyData");
	//data.handData = cfg.getValue<std::string>("handData");
	data.headRef = cfg.getValue<std::string>("headRef");
	data.voiceRef = chr.voiceRef;
}

chars::Character::Character(std::string charDataRef, std::string voiceRef)
	: charDataRef(charDataRef), voiceRef(voiceRef)
{

}

