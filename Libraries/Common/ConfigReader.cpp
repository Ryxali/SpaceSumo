#include "stdafx.h"
#include "ConfigReader.h"

ConfigReader ConfigReader::cr;
ConfigReader::ConfigReader()
{
}


ConfigReader::~ConfigReader()
{
}

void ConfigReader::remove(std::string config)
{
	mConfigs.erase(config);
}

void ConfigReader::clear()
{
	mConfigs.clear();
}