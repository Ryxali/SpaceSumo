#include "stdafx.h"
#include "Config.h"
#include <string>
#include <cassert>
#include "stringH.h"
#include <iostream>
#include <sstream>
#include "error.h"
Config::Config(std::string filePath, bool implicitLoad) : mConfData(), mFilePath(filePath), mFile()
{
	SAssert(str::contains(filePath, ".cfg"), "config file unknown format");
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
	SAssert(mFile.is_open(), "Could not open config file");
	std::string line = "";
	while(std::getline(mFile, line))
	{
		
		
		std::size_t comment = line.find('#', 0);
		if(comment == std::string::npos)
		{
			//Removes Spaces
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
	}
}

void Config::saveConfigChange()
{
	close();
	mFile.open(mFilePath);
	SAssert(mFile.is_open(), "Could not open config file");

	std::string tempString = "";
	std::string line = "";
	while(std::getline(mFile, line))
	{
		std::size_t comment = line.find('#', 0);
		if(comment == std::string::npos)
		{
			//Removes Spaces
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
					std::map<std::string, std::string>::iterator it = mConfData.find(key);
					SAssert( it != mConfData.end(), "Key not found");

					value = it->second;
					
					line = key + " = " + value;
				}
			}
		}
		for( std::size_t i = 0; i < line.length(); i++ )
		{
			tempString.push_back(line.at(i));
		}

		tempString.push_back('\n');
	}
	std::filebuf fb;
	fb.open(mFilePath, std::ios::out);
	std::ostream os(&fb);
	os << tempString;
	fb.close();

}

void Config::close()
{
	mFile.close();
}

template<>
std::string Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	SAssert( it != mConfData.end(), "Key: " + option + " not found");
	 
	return it->second;
}

template<>
int Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	SAssert( it != mConfData.end(), "Key: " + option + " not found");
 
	return std::stoi(it->second);
}

template<>
bool Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	SAssert( it != mConfData.end(), "Key: " + option + " not found");
 
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
		SAssert(false, "Cannot convert " + it->second + " to bool" );
		return false;
	}
	
}

template<>
float Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	SAssert( it != mConfData.end(), "Key: " + option + " not found");
 
	return std::stof(it->second);
}

template<>
double Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	SAssert( it != mConfData.end(), "Key: " + option + " not found");
 
	return std::stod(it->second);
}

template<>
char Config::getValue(std::string option)
{
	std::map<std::string, std::string>::iterator it = mConfData.find(option);
	SAssert( it != mConfData.end(), "Key: " + option + " not found");
 
	SAssert(it->second.length() == 1, "String can't be loaded into a single char");
	return (it->second.at(0));
}