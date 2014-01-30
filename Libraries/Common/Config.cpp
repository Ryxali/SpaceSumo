#include "stdafx.h"
#include "Config.h"
#include <string>
#include <cassert>
#include "stringH.h"
#include <iostream>
#include <sstream>
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
		
		
		std::size_t comment = line.find('#', 0);
		if(comment == std::string::npos)
		{
			std::string::size_type space = line.find(' ');
			while (std::string::npos != space)
			{
				line.erase(space, 1);
				space = line.find(' ');
			}

			std::istringstream is_line(line);
			std::string key;
			if( std::getline(is_line, key, '=') )
			{
				std::string value;
				if( std::getline(is_line, value) ) 
				{
					mConfData.emplace(key, value);
				}
			}
		}


		/*
		std::cout << line << std::endl;
		std::string cName = line.substr(0, line.find_first_of(":"));
		std::cout << "cName: " << cName << std::endl;
		std::string cOption = line.substr(line.find_first_of(":")+2);
		std::cout << "cOption: " << cOption << std::endl;
		*/
	}
}

void Config::close()
{
	mFile.close();
}

template<>
std::string Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	assert( it != mConfData.end());
	 
	return it->second;
}

template<>
int Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	assert( it != mConfData.end());
 
	return std::stoi(it->second);
}

template<>
bool Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	assert( it != mConfData.end());
 
	if(it->second == "false")
	{
		return false;
	}
	else if(it->second == "true")
	{
		return true;
	}
	else
	{
		assert(false);
		return false;
	}
	
}

template<>
float Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	assert( it != mConfData.end());
 
	return std::stof(it->second);
}

template<>
double Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	assert( it != mConfData.end());
 
	return std::stod(it->second);
}

template<>
char Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	assert( it != mConfData.end());
 
	assert(it->second.length() == 1);
	return (it->second.at(0));
}