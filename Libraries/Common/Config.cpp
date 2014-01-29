#include "stdafx.h"
#include "Config.h"
#include <string>
#include <cassert>
#include "stringH.h"
#include <iostream>
Config::Config(std::string filePath, bool implicitLoad) : mConfData(), mFilePath(filePath), mFile()
{
	assert(str::contains(filePath, ".cfg"));
	if(implicitLoad)
	{
		loadToMemory();
	}
}

Config::~Config()
{
	close();
}

void Config::loadToMemory()
{
	mFile.open(mFilePath);
	assert(mFile.is_open());
	std::string line = "";
	while(std::getline(mFile, line))
	{
		std::cout << line << std::endl;
		std::string cName = line.substr(0, line.find_first_of(":"));
		std::cout << "cName: " << cName << std::endl;
		std::string cOption = line.substr(line.find_first_of(":")+2);
		std::cout << "cOption: " << cOption << std::endl;
	}
}

void Config::close()
{
	mFile.close();
}

std::string Config::getValue(std::string option)
{
	return "";
}