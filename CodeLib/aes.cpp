#include "stdafx.h"
#include "aes.h"

namespace clib {

	bool exists(const char* file);
	std::string tmpfile(const char* file);

	unsigned char* AES::initkey(const char* key) {
		int len = std::strlen(key);
		unsigned char* ckey = (unsigned char*)key;
		int nlen = clib::addpadding(ckey, len, (len <= 16) ? 16 : (len <= 24) ? 24 : 32);
		elen = clib::expandkey(ckey, nlen);
		return ckey;
	}

	int AES::encrypt(unsigned char* &data, long length) {
		int nlength = clib::addpadding(data, length, 16);
		long read = 0;
		while (read < nlength) {
			clib::aesencrypt(data + read, ekey, elen);
			read += 16;
		}
		
		return nlength;
	}

	int AES::decrypt(unsigned char* &data, long length) {
		if (length % 16 != 0) { return -1; }

		long read = 0;
		while (read < length) {
			clib::aesdecrypt(data + read, ekey, elen);
			read += 16;
		}
		return clib::removepadding(data, length, 16);
	}

	bool AES::fencrypt(const char* file) {
		std::ifstream istream(file, std::ios::binary);

		std::string tf = tmpfile(file);
		std::ofstream ostream(tf, std::ios::binary);

		if (!istream.is_open()) { return false; }

		constexpr int length = 16;
		unsigned char arr[length];
		unsigned char* buffer = (unsigned char*)arr;

		bool donepadding = false;
		while (istream.read((char*)buffer, length).gcount() > 0) {
			if (istream.gcount() < 16) {
				clib::addpadding(buffer, istream.gcount(), 16);
				donepadding = true;
			}
			clib::aesencrypt(buffer, ekey, elen);
			ostream.write((char*)buffer, 16);
		}

		if (donepadding == false && istream.gcount() == 16) {
			unsigned char* padded = new unsigned char[16];
			std::memset(padded, 16, 16);
			clib::aesencrypt(padded, ekey, elen);
			ostream.write((char*)buffer, istream.gcount());
		}

		istream.close();
		ostream.close();

		if (remove(file) != 0) { return false; }
		if (rename(tf.c_str(), file) != 0) { return false; }

		return true;
	}

	bool AES::fdecrypt(const char* file) {
		std::ifstream istream(file, std::ios::binary);

		std::string tf = tmpfile(file);
		std::ofstream ostream(tf, std::ios::binary);

		if (!istream.is_open()) { return false; }

		constexpr int length = 16;
		unsigned char buffer[length];
		int gc = 0;

		while (istream.read((char*)buffer, length).gcount() > 0) {
			gc = istream.gcount();
			clib::aesdecrypt(buffer, ekey, elen);
			if (istream.peek() == EOF) {
				if (istream.eof()) {
					int newl = clib::removepadding(buffer, gc, 16);
					ostream.write((char*)buffer, newl);
				}
			} else {
				ostream.write((char*)buffer, gc);
			}
		}

		istream.close();
		ostream.close();

		if (remove(file) != 0) { return false; }
		if (rename(tf.c_str(), file) != 0) { return false; }

		return true;
	}

	void AES::set_key(const char* key) {
		ekey = initkey(key);
	}

	unsigned char* AES::get_ekey() {
		return ekey;
	}

	int AES::get_ekey_len() {
		return elen;
	}

	bool exists(const char* file) {
		struct stat buffer;
		return (stat(file, &buffer) == 0);
	}

	std::string tmpfile(const char* file) {
		std::string tmp(file);
		while (exists(tmp.append("_").c_str()));
		return tmp.c_str();
	}

	int addpadding(unsigned char* &data, int data_length, int newsize) {
		int padding = (data_length % newsize == 0) ? 16 : newsize - (data_length % newsize);
		int newlen = data_length + padding;
		unsigned char* newdata = new unsigned char[newlen + 1];
		memcpy(newdata, data, data_length);
		unsigned char* paddingptr = newdata + data_length;
		for (int i = 0; i < padding; i++) {
			*(paddingptr + i) = padding;
		}
		*(paddingptr + padding) = 0x00;
		data = newdata;
		return newlen;
	}

	int removepadding(unsigned char* data, int data_length, int newsize) {
		int new_data_length = (data[data_length - 1] > newsize) ? data_length : data_length - data[data_length - 1];
		if (new_data_length < data_length) { data[new_data_length] = 0x00; }
		return new_data_length;
	}

}