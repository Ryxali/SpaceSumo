#pragma once
#include <fstream>
#include <map>
class Config
{
public:
	/*
		Constructs a new config linked with the file path specified. It can be
		specified to implicitly open, but will implicitly close the stream upon
		destruction.
		param: std::string filePath - the config file path
		param: bool implicitLoad (default: true) - tells the Config whether it should auto open the stream upon construction
	*/
	Config(std::string filePath, bool implicitLoad = true);
	// Destructor
	~Config();
	/*
		Opens up the stream to the config file, then loads its' content into memory.
	*/
	void loadToMemory();
	void saveConfigChange();
	
	template <typename Tval>
	Tval getValue(std::string option);
private:
	/*
		Closes the stream to the config file.
	*/
	void close();
	// std::map<OptionName, OptionValue>
	std::map<std::string, std::string> mConfData;
	std::fstream mFile;
	std::string mFilePath;
};

