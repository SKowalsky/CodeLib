#pragma once

#ifdef CODELIB_EXPORTS
#define CODELIB_API __declspec(dllexport)
#else
#define CODELIB_API __declspec(dllimport)
#endif

#include "aescrypt.h"
#include "padding.h"
#include <fstream>
#include <sys/stat.h>
#include <stdio.h>
#include <string>

namespace clib {

	class AES {
		unsigned char* ekey;
		int elen;

		unsigned char* initkey(const char* key);

	public:
		CODELIB_API AES(const char* key) : ekey(initkey(key)) {};

		CODELIB_API int encrypt(unsigned char* data, long length);
		CODELIB_API int decrypt(unsigned char* data, long length);
		CODELIB_API bool fencrypt(const char* file);
		CODELIB_API bool fdecrypt(const char* file);
	};

}