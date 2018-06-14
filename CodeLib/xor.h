#pragma once

#ifdef CODELIB_EXPORTS
#define CODELIB_API __declspec(dllexport)
#else
#define CODELIB_API __declspec(dllimport)
#endif

#include <string>
#include <fstream>
#include <sys/stat.h>
#include <stdio.h>

namespace clib {
	class XORCipher {
		const char* ckey;
		unsigned long keypos;
		inline void next();
		std::string tmpfile(const char* file);
		inline bool exists(const char* file);

	public:
		CODELIB_API XORCipher(const char* key) : ckey(key), keypos(0) {};

		CODELIB_API char* toggle(char* bytes, int length);
		CODELIB_API bool ftoggle(const char* srcfile);
		
		CODELIB_API const char* get_key() const { return ckey; };
	};
}