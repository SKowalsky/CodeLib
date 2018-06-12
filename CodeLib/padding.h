#pragma once

#ifdef CODELIB_EXPORTS
#define CODELIB_API __declspec(dllexport)
#else
#define CODELIB_API __declspec(dllimport)
#endif


namespace clib{
	
	CODELIB_API int addpadding(unsigned char* &text, int text_length, int multible_of);
	CODELIB_API int removepadding(unsigned char* text, int text_length, int multible_of);
	CODELIB_API int fillup(unsigned char* &text, int text_length, int multible_of);

	CODELIB_API unsigned char* getpadding(int text_length, int multible_of);
}