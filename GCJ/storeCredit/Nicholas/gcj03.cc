/*
Google Code Jam Entrance Test
(Store Credit: https://code.google.com/codejam/contest/351101/dashboard)

Used Algorithm Method: Hashmap and string parsing
Notes: this is equivalent to Twosum problem
Coded by isdemus (May 13 2016)
*/

#include <iostream>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;

// main function handles all the job because the task is small
int main(int argc, char* argv[]) {
	int cases, credit, items;
	cin >> cases;

	// Running the algorithm by the given cases times
	for (int N=1; N<=cases; N++) {
		int givenItem, item_1, item_2;
		string endOfLine;
		map<int, int> twoSumMap;
		map<int, int> indexMap;
		cin >> credit;
		cin >> items;
	
		printf("Input CheckList --- cases: %d\tcredit: %d\titems: %d\n", cases, credit, items);

		// For every item, it stores the value into the hashmap
		// Because of the hashmap use, we can perform the job in O(N)
		for (int I=1; I<=items; I++) {
			cin >> givenItem;
			twoSumMap[givenItem] = credit-givenItem;
			
			// When there was not the same value previously, it inserts the index
			// By adding this if statement, we can avoid a problem with credit = 2 * value with just one value
			if (indexMap[givenItem] == 0)
				indexMap[givenItem] = I; 

			// The if condition must exclude a case with just one value
			if (indexMap[credit - givenItem] != I && twoSumMap[credit-givenItem] == givenItem) {
				item_1 = min(I, indexMap[twoSumMap[givenItem]]);
				item_2 = max(I, indexMap[twoSumMap[givenItem]]);
				break; //saving the energy!
			}	

			indexMap[givenItem] = I;
		}

		getline(cin, endOfLine);

		printf("Case #%d: %d %d\n", N, item_1, item_2);
	}


	return 0;
}
