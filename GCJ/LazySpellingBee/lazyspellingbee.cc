/* 
Google Code Jam Entrance Test 
(https://code.google.com/codejam/contest/5254486/dashboard)

Used Algorithm Method: 
Coded by isdemus (Dec 22 2016)
*/

#include <iostream>
#include <unordered_map>
#include <set>

#define MODCONST 1000000007;

using namespace std;

int main(int argc, char* argv[]) {
	int inputsize;
	string input;
	const long long modconst = 1000000007;

	cin >> inputsize;
	// Continuous input from the standard input
	for (int index = 1; index <= inputsize; index++) {
		unsigned int possible_answer = 1; // self
		cin >> input;
		for (unsigned int charindex = 0; charindex < input.length(); charindex++) {
			std::set<char> possible_char;
			possible_char.insert(input[charindex]);
			if (input.length() == 1) {
				// Do Nothing
			} else if (charindex == 0) {
				possible_char.insert(input[charindex + 1]);
			} else if (charindex == input.length() - 1) {
				possible_char.insert(input[charindex - 1]);
			} else {
				possible_char.insert(input[charindex - 1]);
				possible_char.insert(input[charindex + 1]);
			}
			possible_answer *= possible_char.size();
			possible_answer %= modconst;
		}
		printf("Case #%d : %u\n", index, possible_answer);
	}

	return 0;
}
