/* 
Google Code Jam Entrance Test 
(Saving the universe: https://code.google.com/codejam/contest/32013/dashboard)

Used Algorithm Method: Dynamic Programming
Coded by isdemus (May 01 2016)
*/

#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[]) {
	int testCases, searchEngine, queries;
	string line;
	cin >> testCases;
	getline(cin, line); // end of line


	for (int N=1; N<=testCases; N++) {
		cin >> searchEngine;
		getline(cin, line); // end of line

		map<string, int> engines;
		for (int s=0; s<searchEngine; s++) {
			getline(cin, line); // search engine
			engines[line] = s;
		}

		cin >> queries;
		//cout << "queries: " << queries << endl;
		int queriesArray[queries];
		int optimalSwitch[queries];

		getline(cin, line);
		for (int q=0; q<queries; q++) {
			getline(cin, line);
			queriesArray[q] = engines[line];
		}

		// Consider a system with various search engines as a blackbox
		// It does not matter which statement we use, it matters with the optimum (minimum) number of switches required
		for (int q=0; q<queries; q++) { // For each query, we find/use the optimal switch value from a previous query
			optimalSwitch[q] = queries-1; // begin with the max number of switches required <-> Guaranteed way to save the universe
			for (int s=0; s<searchEngine; s++) { // We apply a query to each search engine to see the compatibility
				if (queriesArray[q] == s) continue; // When we have a query that is the same name of the search engine
				else {
					int qPointer = q;
					for (qPointer; qPointer >= 0 && queriesArray[qPointer] != s; qPointer--) { /* intentionally spaced blank */ }
					if (qPointer == -1)
						optimalSwitch[q] = 0;
					else
						optimalSwitch[q] = min(optimalSwitch[q], optimalSwitch[qPointer] + 1); // Recurrence formula
				}
			}
		}
		

		cout << "Case #" << N << ": " << optimalSwitch[queries-1] << endl;
	}

	return 0;
}