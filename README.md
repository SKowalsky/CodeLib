
# CodeLib

This project is a C++ implementation of the AES algorithm. This library can be used for text and file encryption.
It also includes a XOR Cipher algorithm, which is fast, but also insecure and easily crackable

## Get started
To use the library you can either build it yourself, or just simply copy the following header and source files into your project:

AES:
- aes.h
- aes.cpp

XOR Cipher:
- xor.h
- xor.cpp

## Code Examples

### Encrypting and decrypting text
````cpp
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
}
````

### Encrypting and decrypting files
````cpp
#include "aes.h"

int main()
{
	clib::AES obj("secretkey");
	
	obj.fencrypt("C:\path\to\file\file.txt");	//encrypting file
	
	obj.fdecrypt("C:\path\to\file\file.txt");	//decrypting file
	
	system("pause");
}
````

### Using XOR Cipher
````cpp
#include "xor.h"

int main()
{
	clib::XORCipher obj("secretkey");
	
	obj.ftoggle("C:\path\to\file\file.txt");	//encrypting file
	obj.ftoggle("C:\path\to\file\file.txt");	//decrypting file

	unsigned char text[] = "Plain text";

	obj.toggle(text, text.length);				//encrypting
	std::cout << text << std::endl;

	obj.toggle(text, text.length);				//decrypting
	std::cout << text << std::endl;
	
	system("pause");
}
````

## TODO
- Increase speed and efficiency of file encryption using multi threading
- Figure out how to provide string support