#pragma once

#ifdef CODELIB_EXPORTS
#define CODELIB_API __declspec(dllexport)
#else
#define CODELIB_API __declspec(dllimport)
#endif


namespace clib{
	
	/**
		Adds padding to given text block
		@param data : Text block
		@param data_length : Length of text block
		@param newsize : New length of block
	*/
	CODELIB_API int addpadding(unsigned char* &data, int data_length, int newsize);

	/**
		Removes padding from given text block
		@param data : Text block
		@param data_length : Length of text block
		@param newsize : Size the block was originally padded to
	*/
	CODELIB_API int removepadding(unsigned char* data, int data_length, int newsize);

	/**
		Adds padding to given text block (not reversable)
		@param data : Text block
		@param data_length : Length of text block
		@param newsize : New length of block
	*/
	CODELIB_API int fillup(unsigned char* &data, int data_length, int newsize);

	/**
		Returns padding for block with given length
		@param text : Length of text block
		@param newsize : New length of block
	*/
	CODELIB_API unsigned char* getpadding(int text_length, int newsize);

}