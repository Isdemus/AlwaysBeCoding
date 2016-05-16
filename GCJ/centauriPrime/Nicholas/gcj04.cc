/*
Google Code Jam Entrance Test
(Centauri Prime: https://code.google.com/codejam/contest/956485/dashboard)

Used Algorithm Method: Basic knowledge of pointer, printf, and if/else statement
Coded by isdemus (May 16 2016)
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	int cases; string line;
	char vowel[] = {'a', 'e', 'i', 'o', 'u'};
	cin >> cases;

	getline(cin, line); // end of line
	for (int c=1; c<=cases; c++) {
		bool ruleByQueen = false;
		getline(cin, line);
		char lastLetter = line[line.length()-1];
		for (int size=4; size>=0; size--) {
			if (*(vowel+size) == lastLetter) {
				ruleByQueen = true;
				break;
			}
		}

		printf("Case #%d: %s is ruled by", c, line.c_str());
		if (ruleByQueen) 
			printf(" a queen");
		else if (line[line.length()-1] == 'y')
			printf(" nobody");
		else
			printf(" a king");

		printf(".\n");
	}

	return 0;
}
