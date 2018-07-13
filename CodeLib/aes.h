#pragma once

#ifdef CODELIB_EXPORTS
#define CODELIB_API __declspec(dllexport)
#else
#define CODELIB_API __declspec(dllimport)
#endif

#include "aescrypt.h"
#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>

namespace clib {

	class AES {
		unsigned char* ekey;
		int elen;
		unsigned char* initkey(const char* key);

	public:
		/**
			Constructor
			@param key : Key to encrypt / decrypt
		*/
		CODELIB_API AES(const char* key) : ekey(initkey(key)) {};

		/**
			Encrypt text
			@param data : Data to encrypt
			@param length : Length of data block
			@return Size of the encrypted data block
		*/
		CODELIB_API int encrypt(unsigned char* &data, long length);

		/**
			Decrypt text
			@param data : Data to decrypt
			@param length : Length of data block
			@return Size of the decrypted data block
		*/
		CODELIB_API int decrypt(unsigned char* &data, long length);

		/**
			Encrypt file
			@param file : File to encrypt
		*/
		CODELIB_API bool fencrypt(const char* file);

		/**
			Decrypt file
			@param file : File to decrypt
		*/
		CODELIB_API bool fdecrypt(const char* file);

		CODELIB_API void set_key(const char* key);
		CODELIB_API unsigned char* get_ekey();
		CODELIB_API int get_ekey_len();
	};

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

}