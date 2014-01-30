#include "stdafx.h"
#include "error.h"

#include <windows.h>
#include "stringH.h"
#include <sstream>
#include <strstream>




/* File scope functions */
static std::string stripPathInformation(const std::string &filename){
	std::string            strippedFilename(filename);
	std::string::size_type indexOfLastBackslash = strippedFilename.find_last_of('\\');
	if(std::string::npos != indexOfLastBackslash){
		strippedFilename.erase(0, indexOfLastBackslash + 1);
	}
	return strippedFilename;
}



/* VGCAssertBox */
	
/* Public functions */
void VGCAssertBox::messageBox(const std::string &expression, const std::string &filename, int lineNumber, std::string line){

	if(line == "\"\"")
	{
		line = "No specific info provided";
	}

	line.replace(line.begin(), line.begin()+1, "");
	line.replace(line.end()-1, line.end(), "");
	std::string total = expression + "\n\nFile: " + stripPathInformation(filename) + "\n\nLine: " + std::to_string(lineNumber) + "\n\n" + line;
	std::wstring wexpression(total.begin(), total.end());
	 
	MessageBoxW(NULL, wexpression.c_str(), L"Assertion failure", MB_OK);
}