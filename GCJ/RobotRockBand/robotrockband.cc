#include <iostream>
#include <list>
#include <vector>

#define SETNUM 4

using namespace std;

int main(int argc, char* argv[]) {
	unsigned int cases, number, answer;
	unsigned long goal, temp;

	cin >> cases;
	for (unsigned int c = 1; c <= cases; c++) {
		list<unsigned int> answerlist;
		answerlist.push_back(0);
		answer = 0;
		cin >> number >> goal;

		// Input from each set (gruop)
		for (int setindex = 0; setindex < SETNUM; setindex++) {
			vector<unsigned int> lastanswer;
			const int listsize = answerlist.size();
			lastanswer.reserve(listsize);

			// Moving the last answer into a vector from the list
			for (int index = 0; index < listsize; index++) {
				lastanswer.push_back(answerlist.front());
				answerlist.pop_front();
			}

			// For each value in the set, store the XOR result into the list
			for (unsigned int pairnum = 0; pairnum < number; pairnum++) {
				cin >> temp;
				for (unsigned int index = 0; index < listsize; index++) {
					unsigned int ans = temp ^ lastanswer.at(index);
					answerlist.push_back(temp ^ lastanswer.at(index));
				}
			}
		}

		// Checking how many ways are possible (finding a value of zero)
		while (!answerlist.empty()) {
			unsigned int finalnumber = answerlist.front();
			if (finalnumber == 0) {answer += 1;}
			answerlist.pop_front();
		}

		printf("Case #%u: %u\n", c, answer);
	}
	return 0;
}
