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
		CODELIB_API int encrypt(unsigned char* data, long length);

		/**
			Decrypt text
			@param data : Data to decrypt
			@param length : Length of data block
			@return Size of the decrypted data block
		*/
		CODELIB_API int decrypt(unsigned char* data, long length);

		/**
		Encrypt text
		@param data : Data to encrypt
		@return Encrypted data
		*/
		CODELIB_API std::string encrypt(std::string data);

		/**
		Decrypt text
		@param data : Data to decrypt
		@return Decrypted data
		*/
		CODELIB_API std::string decrypt(std::string data);

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
	};

}