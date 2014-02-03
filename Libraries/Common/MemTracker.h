/*
	Courtesy of Viktor Karlsson, group 9.
*/
#ifndef MEMTRACKER_H
#define MEMTRACKER_H
	#if defined(_DEBUG) && !defined(NO_MEMORY_TRACKING)
		void dumpMemoryBuffer();
		void* operator new( size_t size, const char* file, unsigned int line );
		void  operator delete( void* memory, const char* file, unsigned int line);
		void  operator delete( void* memory );
		#define new new(__FILE__, __LINE__)
		#define DUMP_MEMORY_BUFFER dumpMemoryBuffer()
	#else
		#define DUMP_MEMORY_BUFFER sizeof(0)
	#endif
#endif