#pragma once
#include <map>
#include <string>
#include "Config.h"
class ConfigReader
{
public:
	template <typename Tval>
	static inline Tval getValue(std::string config, std::string option)
	{
		if(cr.mConfigs.count(config) == 0)
		{
			cr.mConfigs.emplace(config, config);
		}
		return cr.mConfigs.at(config).getValue<Tval>(option);
	}

	void remove(std::string config);

	void clear();
private:
	ConfigReader();
	ConfigReader(const ConfigReader& cr);
	ConfigReader& operator=(const ConfigReader& cr);
	~ConfigReader();
	static ConfigReader cr;
	std::map<std::string, Config> mConfigs;
};

