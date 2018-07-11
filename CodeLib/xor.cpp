#include "stdafx.h"
#include "xor.h"

namespace clib {

	inline void XORCipher::next() {
		if (keypos++ >= (unsigned)strlen(ckey)) { keypos = 0; }
	}

	char* XORCipher::toggle(char* bytes, int length) {
		for (int i = 0; i < length; i++) {
			bytes[i] = ckey[keypos] ^ bytes[i];
			next();
		}
		return bytes;
	}

	bool XORCipher::ftoggle(const char* file) {
		std::ifstream istream(file, std::ios::binary);

		std::string tf = tmpfile(file);
		std::ofstream ostream(tf, std::ios::binary);

		if (!istream.is_open()) { return false; }

		constexpr int length = 4096;
		char buffer[length];

		while (istream.read(buffer, length).gcount() > 0) {
			ostream.write(toggle(buffer, length), istream.gcount());
		}

		istream.close();
		ostream.close();

		if (remove(file) != 0) { return false; }
		if (rename(tf.c_str(), file) != 0) { return false; }

		return true;
	}

	inline std::string XORCipher::tmpfile(const char* file) {
		std::string tmp(file);
		while (exists(tmp.append("_").c_str()));
		return tmp;
	}

	inline bool XORCipher::exists(const char* file) {
		struct stat buffer;
		return (stat(file, &buffer) == 0);
	}

}