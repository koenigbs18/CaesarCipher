#include "CaesarCipher.h"

CaesarCipher::CaesarCipher() {
	// Unused
}

CaesarCipher::~CaesarCipher() {
	// Unused
}

/*
Function decrypt
input:       std::string: String to be decrypted
output:      std::string: Decrypted string
description: This function uses a for loop to iterate through the
			 decrypted string and a stringstream is used to concatenate the modifed
			 char's of the decrypted string before being passed to a user input
			 function to determine the decryption status.  Once the user input
			 function has returned true, the function returns the decrypted
			 string.
*/
std::string CaesarCipher::decrypt(std::string toDecrypt) {
	// stringstream for concatenating the decrypted string
	std::stringstream ss;
	// Save the original for calculating the distance
	std::string original = toDecrypt;
	int key = 0;
	bool userInput = false;
	// Loop while the user has determined the string is not decrypted
	while (userInput != true) {
		std::stringstream ss;
		for (int i = 0; i < toDecrypt.length(); i++) {
			// Get the current char in the loop
			char curr = toDecrypt.at(i);
			// Increment the char by 1 ascii value if it's not our delimiter
			if(curr != ' ')
				curr--;
			// Fix the char in the current loop
			fixChar(curr, 65, 90, ' ');
			// Add it to the stringstream
			ss << curr;
		}
		// Save the current modified string
		toDecrypt = ss.str();
		// Prompt the user to determine whether the string was decrypted
		userInput = userDeterminedDecryption(ss.str());
	}
	// Calculate the key
	key = original.at(0) - toDecrypt.at(0);
	// Print the key
	std::cout << "\n\nkey: " << key << " character shift.";
	// Return the decrypted string
	return toDecrypt;
}

/*
Function fixChar
input:       char&: address of char to be checked/fixed, int: high/low ascii bounds
output:      bool: Success value of function
description: This function returns true when the char has been
			 fixed to be within the passed ASCII boundries.
			 When upper bound is hit, the char's ASCII value
			 is set to the lowest bound and vice versa.
*/
bool CaesarCipher::fixChar(char& toFix, int lowerBound, int upperBound, char delimiter) {
	// return false if the char is already within the proper bounds
	if ((toFix >= lowerBound && toFix <= upperBound) || (toFix == delimiter))
		return false;
	// Setting the char to the proper bounds (high/low)
	if (toFix < lowerBound)
		toFix = upperBound;
	if (toFix > upperBound)
		toFix = lowerBound;
	// Return true once the char has been fixed
	return true;
}

/*
Function userDeterminedDecryption
input:       std::string: decrypted string
output:      bool: user determined decryption success
description: This function returns true when the user has
			 confirmed that the string has been decrypted
			 via keyboard input.
*/
bool CaesarCipher::userDeterminedDecryption(std::string str) {
	// Clear previous input
	system("clear");
	char answer;
	std::cout << str;
	std::cout << "\n\nWas the string decrypted?";
	std::cout << "\n\nEnter y / n.";
	// Prompt user input
	std::cin >> answer;
	// Determine return value via switch statement
	while (answer != 'y' || answer != 'Y' || answer != 'n' || answer != 'N') {
		switch (answer) {
		case 'y':
			return true;
		case 'Y':
			return true;
		case 'n':
			return false;
		case 'N':
			return false;
		}
		std::cout << "\nIncorrect value!";
		std::cout << "\n\nWas the string decrypted?";
		std::cout << "\n\nEnter y / n.";
		// Prompt user input
		std::cin >> answer;
	}
}
