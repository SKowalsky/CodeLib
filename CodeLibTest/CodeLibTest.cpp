#include "stdafx.h"
#include "aes.h"

int main()
{
	std::string plain("Secret text");

	clib::AES crypt("secretkey");

	std::string encrypted = crypt.encrypt(plain);
	std::cout << "'" << encrypted << "'" << std::endl;

	std::string decrypted = crypt.decrypt(encrypted);
	std::cout << "'" << decrypted << "'" << std::endl;

	system("pause");

    return 0;
}