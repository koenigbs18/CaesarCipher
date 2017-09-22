// @TODO: Add decryption
#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

class CaesarCipher {
public:
	CaesarCipher(); // Unused default constructor
	~CaesarCipher(); // Unused default destructor
	static std::string decrypt(std::string);
private:
	static bool fixChar(char&, int, int, char);
	static bool userDeterminedDecryption(std::string);

};

#endif