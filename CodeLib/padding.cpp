#include "stdafx.h"
#include "padding.h"
#include <iostream>

namespace clib {

	int addpadding(unsigned char* &data, int data_length, int newsize) {
		int padding = (data_length % newsize == 0) ? 16 : newsize - data_length;
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

	int fillup(unsigned char* &data, int data_length, int newsize) {
		if (data_length % newsize == 0 && data_length > 0) { return data_length; }
		int padding = newsize - data_length;
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

	unsigned char* getpadding(int data_length, int multible_of) {
		int padding = (data_length % multible_of == 0) ? multible_of : multible_of - data_length;
		unsigned char* padded = new unsigned char[padding + 1];
		for (int i = 0; i < padding; i++) {
			*(padded + i) = padding;
		}
		*(padded + padding) = 0x00;
		return padded;
	}

}