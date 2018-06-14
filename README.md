
# CodeLib

This project is a C++ implementation of the AES algorithm. This library can be used for text and file encryption.

## Get started
To use the library you can either build it yourself, or just simply copy the following header and source files into your project:

- aes.h
- aes.cpp

## Code Examples

### Encrypting and decrypting text
````cpp
#include "aes.h"

int main()
{
	clib::AES obj("secretkey");

	unsigned char text[] = "Plain text";
	int length = obj.encrypt(text, sizeof(text)); //encryption (returns length of encrypted text)
	std::cout << text << std::endl;

	length = obj.decrypt(text, length);	//decryption (returns length of decrypted text)
	std::cout << text << std::endl;
	
	system("pause");
}
````

### Encrypting and decrypting a string
! This is currently unsafe and it is not recommended to use this. Please use the text encryption as described above instead !

````cpp
#include "aes.h"

int main()
{
	clib::AES obj("secretkey");	//create a new AES object
	
	std::string plain("Plain text");
	
	std::string encrypted = crypt.encrypt(plain);	//encrypt string
	std::cout << encrypted << std::endl;
	
	std::string decrypted = crypt.decrypt(encrypted);	//decrypt string
	std::cout << decrypted << std::endl;
	
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

## TODO
- Increase speed and efficiency of file encryption using multi threading