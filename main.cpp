/*
************************************
@Title:  Caesar Cipher
@Author: Brett Koenig
@Date:   9/21/17
************************************
*/
#include <iostream>
#include <string>
#include "CaesarCipher.h"


int main()
{
	// Clear system
	system("clear");
	// Prompt user to input string to be decrypted
	std::cout << "Enter string to decrypt: ";
	std::string toDecrypt;
	std::getline(std::cin, toDecrypt);
	// Decrypt string via CaesarDecrypt's decrypt function.
	std::string decryptedString = CaesarCipher::decrypt(toDecrypt);
	// Output decrypted string.
	std::cout << "\nThe decrypted string is " << decryptedString << "\n";
	return 0;
}
