#include <iostream>
#include <string>
#include <cassert>

#define DIVISOR 11

using namespace std;

int main(int argc, char* argv[])
{
	string given_num = "143"; // Random given number
	string number = given_num; // Safe to use

	cout << "Given number : " << given_num << endl;

	// Figure out if the given number in string is divisble by 11 or not
	while (number.length() > 2) {
		char first_digit  = number[0];
		char second_digit = number[1];

		int highest_digits = (first_digit + '0') * 10 + (second_digit + '0');

		// When highest_digits is less than 11 (e.g., 10)
		if (highest_digits < DIVISOR) {
			char third_digit = number[2];
			highest_digits *= 10;
			highest_digits += (third_digit + '0');

			number[2] = number[2] - 1;
			number = number.substr(2, number.length() - 1);
			continue;
		}

		int highest_remainder = highest_digits % DIVISOR;
		cout << "highest_remainder : " << highest_remainder << endl;

		if (highest_remainder == 0) {
			number = number.substr(2, number.length() - 2);
		} else if (highest_remainder > 10) {
			number[0] = (highest_remainder / 10) + '0';
			number[1] = (highest_remainder % 10) + '0';
		} else {
			number[1] = highest_remainder + '0';
			number = number.substr(1, number.length() - 1);
		}
	}

	// Expected: the string has length 2
	// If the string[0] == string[1], it's divisible by 11.
	// Else, it is not divisible
	assert(number.length() == 2);

	if (number[0] == number[1]) {
		cout << "Yes, divisible by 11" << endl;
		return 0;
	}
	cout << "No, not divisible by 11" << endl;

	return 0;
}
