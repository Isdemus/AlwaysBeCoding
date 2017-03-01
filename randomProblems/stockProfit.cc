/*
 *	Stock Market Problem
 *	Problem Description : 
 *	Suppose we could access yesterday's stock prices as a list, where:
 *	The indices are the time in minutes past trade opening time, which was 9:30am local time.
 *	The values are the price in dollars of Apple stock at that time.
 *	So if the stock cost $500 at 10:30am, stock_prices_yesterday[60] = 500.
 *	Write an efficient function that takes stock_prices_yesterday and returns the best profit I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.
 */

#include <iostream>
#include <fstream>
#include <array>
#include <set>

#define INPUTFILE 0
#define ARRSIZE(arr) (sizeof(arr) / sizeof(*arr))

using namespace std;

// Printing all values in the array with indexes as multiples of 30
void printvalues(const int stocklist[], const int leng) {
	for (int index = 0; index < leng; index++) {
		cout << "index : " << index << " value : " << stocklist[index] << endl;
	}
}

int main(int argc, char* argv[]) {
#if INPUTFILE
	int input;
	string filename = "stock.txt";
	ifstream filetoread (filename, ios::in);

	if (!filetoread.good()) {
		cerr << "Cannot open the file with a name : " << filename << endl;
		return -1;
	}

	array<int, 30*48> stocklist;
	int infocount = 0;
	int startmin  = 0;

	// One example would be that [7, 51, 25, 4, 34, 20, 23, 45, 29, 1, 45, 23]
	// With each index as a multiple of 30 min
	while (filetoread >> input) {
		stocklist[startmin] = input;
		startmin += 30;
		infocount += 1;
	}
#endif

	int stocklist[] = {7, 51, 25, 4, 34, 20, 23, 45, 29, 1, 45, 23};

	// Checking up the list of stock values
	printvalues(stocklist, ARRSIZE(stocklist));

	// Testing : with above input, it will produce 44 (buying at $1 and selling at $45)
	// If there exists less than 2 data in the array, output an error msg
	if (ARRSIZE(stocklist) < 2) {
		cerr << "Not enough data given" << endl;
		return -1;
	}
	
	int minindex = 0;
	int profit = stocklist[minindex + 1] - stocklist[minindex];
	set<pair<int, int>> best_interval;
	best_interval.insert(make_pair(minindex, minindex + 1));

	cout << "begin profit : " << profit << endl;
	for (int index = 1; index < ARRSIZE(stocklist); index++) {
		int stockvalue = stocklist[index];
		if (profit <= stockvalue - stocklist[minindex]) {
			profit = stockvalue - stocklist[minindex];
			best_interval.insert(make_pair(minindex, index));
		}
		minindex = (stocklist[minindex] < stockvalue ? minindex : index);
	}
	cout << "Max profit is : " << profit << endl << endl;

	for_each(best_interval.begin(), best_interval.end(), [=] (pair<int, int> per) {
		if (stocklist[per.second] - stocklist[per.first] == profit) {
			cout << "Buying at index : " << per.first << " at a price : " << stocklist[per.first] << endl;
			cout << "Selling at index : " << per.second << " at a price : " << stocklist[per.second] << endl;
			cout << endl;
		}
	});
	
	return 0;
}
