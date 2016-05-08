
/* 
Google Code Jam Entrance Test 
(Alien Language: https://code.google.com/codejam/contest/90101/dashboard)

Used Algorithm Method: 
Coded by isdemus (May 03 2016)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void display_vec(vector<string>* vec) {
	for (vector<string>::iterator it=vec->begin(); it!=vec->end(); it++) {
		cout << *it << endl;
	}
}

int main(int argc, char* argv[]) {
	int wordLength, wordSize, possibleDictionary;
	vector<string>* vec = new vector<string>();
	string word;

	cin >> wordLength;
	cin >> wordSize;
	cin >> possibleDictionary;

	getline(cin, word); //end of line
	for (int words=0; words<wordSize; words++) {
		getline(cin, word);
		vec->push_back(word);
	}

	display_vec(vec);

	return 0;
}