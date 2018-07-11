#include "stdafx.h"
#include "aes.h"

int main()
{
	clib::AES obj("secretkey!");

	std::string s = std::string("Plain text");
	unsigned char * text = (unsigned char*)s.c_str();

	int length = obj.encrypt(text, s.size());
	std::cout << text << std::endl;

	length = obj.decrypt(text, length);
	std::cout << text << std::endl;

	system("pause");

	return 0;
}