
/* 
Google Code Jam Entrance Test 
(Alien Language: https://code.google.com/codejam/contest/90101/dashboard)

Used Algorithm Method: Knowledge of vector, hashmap, and string parsing
Coded by isdemus (May 03 2016)
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;

void display_vec(vector<string>* vec) {
	for (vector<string>::iterator it=vec->begin(); it!=vec->end(); it++) {
		cout << *it << endl;
	}
}

int main(int argc, char* argv[]) {
	int wordLength, wordSize, possibleDictionary;
	vector<string>* vec = new vector<string>(); // As D can be 5000, use heap
	string word;

	cin >> wordLength;
	cin >> wordSize;
	cin >> possibleDictionary;

	getline(cin, word); //end of line
	for (int words=0; words<wordSize; words++) {
		getline(cin, word);
		vec->push_back(word);
	}

	// Parsing the input of the possible dictionaries
	for (int dict=1; dict<=possibleDictionary; dict++) {
		// Outer vector has the size of "wordSize"
		vector < map<char, bool> > dictList;

		int wordPosition = 0; int character; int answer = 0;
		bool inProgress = false;
		map<char,bool> dictionary;
		while (wordPosition < wordLength) {
			character = getchar();
			
			if (character == (int)'\n')
				continue;
			else if (character == (int)'(')
				inProgress = true;
			else if (character == (int)')')
				inProgress = false;
			else
				dictionary[(char)character] = true;
			
			if (!inProgress) {
				wordPosition++;
				dictList.push_back(dictionary);
				dictionary = map<char,bool>();
			}
		}

		for (vector<string>::iterator it=vec->begin(); it!=vec->end(); it++) {
			string word = *it;
			for (int wordPosition=0; wordPosition<word.length(); wordPosition++) {
				map<char, bool> dictionary = dictList[wordPosition];
				if (!dictionary[word[wordPosition]])
					break;
				else if(wordPosition == word.length()-1)
					answer++;
			}
		}

		cout << "Case #" << dict << ": " << answer << endl;
	}

	//display_vec(vec);

	return 0;
}