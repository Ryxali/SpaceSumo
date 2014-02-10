/*
	Courtesy of Viktor Karlsson, group 9.
*/
#include "stdafx.h"
#include "MemTracker.h"
#include "stringH.h"
#include <iostream>
#include <malloc.h>
#include <vector>



#undef new

struct MemoryInformation
{
	const char* file;
	unsigned int line;
	unsigned int size;
	unsigned long address;
};

static MemoryInformation info;
static std::vector< MemoryInformation > archive;


void* operator new( size_t size, const char* file, unsigned int line) {
	void* memory = operator new(size);
	
	info.file = file;
	info.size = size;
	info.line = line;
	info.address = ( unsigned long ) memory;

	archive.push_back( info );

	return memory;
}

void operator delete( void* memory, const char* file, unsigned int line) {
	delete(memory);
}

void operator delete(void* memory) {
	for( unsigned i = 0; i < archive.size(); i++) {
		if( archive[i].address == ( unsigned long ) memory ) {
			archive.erase(archive.begin() + i);
			break;
		}
	}
	free(memory);
}

void dumpMemoryBuffer() {
	
	for( unsigned i = 0; i < archive.size(); i++ ) {
		std::string fileLine(archive[i].file);
		fileLine = "..." + (std::string)fileLine.substr(fileLine.find_last_of('\\')-16, fileLine.length());
		std::cout << "Leak of memory at:" << std::endl << "    " << fileLine << std::endl << "		 At Line: " << archive[i].line << std::endl;
	}
}