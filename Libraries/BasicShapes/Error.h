#include <cassert>
#include <string>
#undef assert
namespace Error {
	void warn(std::string string);
	void error(std::string string);
	void assert(_Expression);
};

void Error::warn(std::string string)
{

}
