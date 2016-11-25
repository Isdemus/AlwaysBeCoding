#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

bool CompareHashTable(const unordered_map<char, size_t> &firsttable,
											const unordered_map<char, size_t> &secondtable) {
	for (auto letter : firsttable) {
		if (firsttable.at(letter.first) != secondtable.at(letter.first))
			return false;
	}
	return true;
}

vector<size_t> * GetAnagramIndices(const string& sent, const string& pattern) {
	vector<size_t> *indices = nullptr;
	unordered_map<char, size_t> patterntable;
	unordered_map<char, size_t> senttable;
	size_t senttableindex = 0;
	size_t patternleng    = pattern.length();
	size_t sentleng       = sent.length();

	// Filling out the hash table for the pattern
	for (char letter : pattern) {
		patterntable[letter] += 1;
	}
	// Filling out the hash table for the sent from index 0 to the length of pattern
	for (size_t index = 0; index < patternleng; index++) {
		senttable[sent[index]] += 1;
	}

	for (size_t index = 0; index < sentleng - patternleng; index++) {
		// Need to update the hash table for the sent
		while (senttableindex != index) {
			senttable[sent[senttableindex]] -= 1;
			senttable[sent[senttableindex + patternleng]] += 1;
			senttableindex += 1;
		}
		if (CompareHashTable(patterntable, senttable)) {
			if (indices == nullptr) {
				indices = new vector<size_t>();
			}
			indices->push_back(index);
		}
	}
	return indices;
}

int main(int argc, char* argv[]) {
  string givenstring, pattern;
	cin >> givenstring >> pattern;

	auto solution = GetAnagramIndices(givenstring, pattern);
	if (solution != nullptr) {
		cout << "There are " << solution->size() << " anagrams found" << endl;
		if (solution->size() > 1) {
			cout << "The indexes are at :";
		} else {
			cout << "The index is at :";
		}
		for (size_t index : *solution) {
			cout << " " << index;
		}		
		cout << endl;
		delete solution;
	}
  return 0;
}
