#pragma once

#ifdef CODELIB_EXPORTS
#define CODELIB_API __declspec(dllexport)
#else
#define CODELIB_API __declspec(dllimport)
#endif

#include <iostream>
#include <ios>

namespace clib {

	//	KEY EXPANSION
	CODELIB_API int expandkey(unsigned char* &key, int key_size);
	inline void rotword(unsigned char* key);
	inline void subword(unsigned char* key);
	inline char rcon(unsigned char num);

	//	AES ENCRYPTION
	CODELIB_API void aesencrypt(unsigned char* block, unsigned char* ekey, int ekey_size);
	inline void addroundkey(unsigned char* block, unsigned char* key);
	inline void shiftrow(unsigned char* block);
	inline void bytesub(unsigned char* block, unsigned char* psbox);
	inline void mixcolumn(unsigned char* block, int* pmatrix);

	//	AES DECRYPTION
	CODELIB_API void aesdecrypt(unsigned char* block, unsigned char* ekey, int ekey_size);
	inline void inv_shiftrow(unsigned char* block);

	//	OTHER
	CODELIB_API inline char galois_multiplication(unsigned char a, unsigned char b);
	CODELIB_API void printhex(unsigned char* c, int len);

	extern unsigned char sbox[256];
	extern unsigned char inv_sbox[256];
	extern unsigned char rconbox[255];
	extern int matrix[16];
	extern int inv_matrix[16];
	extern unsigned char galois_e[256];
	extern unsigned char galois_l[256];

}