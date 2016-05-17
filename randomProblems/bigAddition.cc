#include <iostream>
#include <string>
using namespace std;

#define DATELEN 8;

// spacingFormat: String, Int -> String
// The function returns the string with space(blank) before the string value such that
// the total length will be equal to the given integer.
string spacingFormat (string number, unsigned int spaces) {
	string newNumber = "";
	for (unsigned int m=0; m<spaces-number.length(); m++) {
		newNumber = newNumber + " ";
	}

	return newNumber + number;
}

// bAddition: String, String -> String
// For any high numbers, this addition function can be used if given two numbers as string variables.
// P.S. For an addition of more than two numbers, choose a recursive way to calculate
string bAddition (string number1, string number2) {
	string* resultString = &number2;
	int number1_index    = number1.length()-1;
	int number2_index    = number2.length()-1;
	unsigned int upgrade	      = 0;
	int size	      = number2_index;

	/* Display two numbers */
	cout << " " + spacingFormat(number1, 80) << endl;
	cout << "+" + spacingFormat(number2, 80) << endl;


	if (number1.length() > number2.length()) {
		resultString = &number1;
		size	     = number1_index;
	}

	for (size; size>=0; size--) {
		unsigned int digit1 = 0;
		unsigned int digit2 = digit1;

		if (number1_index >= 0) 
			digit1 = (unsigned int)number1[number1_index] - 48;
		if (number2_index >= 0)
			digit2 = (unsigned int)number2[number2_index] - 48;

		int sum = digit1 + digit2 + upgrade;
		if (sum >= 10) {
			upgrade = 1;
			sum = sum%10;
		}else 
			upgrade = 0;
	
		(*resultString)[size] = (char)(sum + 48);

		number1_index -= 1;
		number2_index -= 1;
	}

	if (upgrade)
		*resultString = "1" + *(resultString);

	return *resultString;
}

// Main Function
int main (int argc, char* argv[]) {
	// Testing: 16734 + 4321 = 21055;
	string str1 = "16734";
	string str2 = "4321";

	cout << spacingFormat(bAddition(str1, str2), 81) << endl;
	
	return 0;
}
