#ifndef SPACESUMO_COMMON_ERROR_INCLUDED
#define SPACESUMO_COMMON_ERROR_INCLUDED

#include <string>

struct VGCAssertBox{
	
	/* Public functions */
	static void messageBox(const std::string &expression, const std::string &filename, int lineNumber, std::string line);
};



#ifdef NDEBUG
#define SDebugAssert(exp) ((void)0)
#define SReleaseAssert(exp) if(!(exp)){VGCAssertBox::messageBox(#exp, __FILE__, __LINE__); std::exit(0);} ((void)0)
#else
#define SDebugAssert(exp) if(!(exp)){VGCAssertBox::messageBox(#exp, __FILE__, __LINE__); std::exit(0);} ((void)0)
#define SReleaseAssert(exp) ((void)0)
#endif

#define SAssert(exp, line) if(!(exp)){VGCAssertBox::messageBox(#exp, __FILE__, __LINE__, line); std::exit(0);} ((void)0)
#define SError(msg, addInfo) if(true){VGCAssertBox::messageBox(msg, __FILE__, __LINE__, addInfo); std::exit(0);} ((void)0)

#endif