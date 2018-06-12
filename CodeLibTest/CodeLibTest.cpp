#include "stdafx.h"
#include "aes.h"

int main()
{
	std::string file;
	std::cout << "File: ";
	std::getline(std::cin, file);

	std::string key;
	std::cout << "Key: ";
	std::getline(std::cin, key);

	std::string ed;
	std::cout << "ED: ";
	std::getline(std::cin, ed);

	if (ed._Equal("e")) {
		std::cout << "Encrypting...";
		clib::AES obj(key.c_str());
		obj.fencrypt(file.c_str());
		std::cout << "Success" << std::endl;
		system("pause");
	} else if (ed._Equal("d")) {
		std::cout << "Decrypting...";
		clib::AES obj(key.c_str());
		obj.fdecrypt(file.c_str());
		std::cout << "Success" << std::endl;
		system("pause");
	}

    return 0;
}