#include "stdafx.h"
#include "aes.h" //import this

int main()
{
	clib::AES obj("secretkey");

	std::string text("Super secred text, nobody can know about.");

	std::string encr = obj.encrypt(text);
	std::cout << encr << std::endl;

	std::string decr = obj.decrypt(encr);
	std::cout << decr << std::endl;


	system("pause");

    return 0;
}