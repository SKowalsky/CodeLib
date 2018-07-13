#pragma once

#ifdef CODELIB_EXPORTS
#define CODELIB_API __declspec(dllexport)
#else
#define CODELIB_API __declspec(dllimport)
#endif

namespace clib {

	/**
		Expands given key to specific size
		@param key : Key to expand
		@param key_size : Size of key. Must be 16, 24 or 32
		@return Size of the expanded key
	*/
	CODELIB_API int expandkey(unsigned char* &key, int key_size);

	inline void rotword(unsigned char* key);
	inline void subword(unsigned char* key);
	inline char rcon(unsigned char num);

	/**
		Encrypts given block
		@param block : 16 Byte block
		@param ekey : Expanded key
		@param ekey_size : The size of the expanded key
	*/
	CODELIB_API void aesencrypt(unsigned char* block, unsigned char* ekey, int ekey_size);

	inline void addroundkey(unsigned char* block, unsigned char* key);
	inline void shiftrow(unsigned char* block);
	inline void bytesub(unsigned char* block, unsigned char* psbox);
	inline void mixcolumn(unsigned char* block, int* pmatrix);

	/**
		Decrypts given block
		@param block : 16 Byte block
		@param ekey : Expanded key
		@param ekey_size : The size of the expanded key
	*/
	CODELIB_API void aesdecrypt(unsigned char* block, unsigned char* ekey, int ekey_size);
	inline void inv_shiftrow(unsigned char* block);

	/**
		Muliplication of two values using the galois field
		@param a : First Byte
		@param b : Second Byte
		@return Product of the multiplication
	*/
	CODELIB_API inline char galois_multiplication(unsigned char a, unsigned char b);

	/**
		Prints hex representation of given char array
		@param c : Char array
		@param len : Length of the array
	*/
	CODELIB_API void printhex(unsigned char* c, int len);


	//Tables
	extern unsigned char sbox[256];
	extern unsigned char inv_sbox[256];
	extern unsigned char rconbox[255];
	extern int matrix[16];
	extern int inv_matrix[16];
	extern unsigned char galois_e[256];
	extern unsigned char galois_l[256];

}