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

using namespace std;

/* 
 *	Printing all values in the array with indexes as multiples of 30
 */
template<std::size_t SIZE>
void printvalues(array<int, SIZE> stocklist, int infocount) {
	for (int index = 0; index < infocount; index++) {
		cout << "index : " << index << " value : " << stocklist[30 * index] << endl;
	}
}

int main(int argc, char* argv[]) {
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

	// One example would be that [7, 5, 25, 4, 34, 20, 23, 45, 29, 1, 45, 23]
	// With each index as a multiple of 30 min
	while (filetoread >> input) {
		stocklist[startmin] = input;
		startmin += 30;
		infocount += 1;
	}

	// Checking up the list of stock values
	printvalues(stocklist, infocount);

/*
 *	Testing : with above input, it will produce 44 (buying at $1 and selling at $45)
 */
	// If there exists less than 2 data in the array, output an error msg
	if (infocount < 2) {
		cerr << "Not enough data given" << endl;
		return -1;
	}
	
	int min = stocklist[0];
	int profit = stocklist[30] - min;
	cout << "begin profit : " << profit << endl;
	for (int index = 1; index < infocount; index++) {
		int stockvalue = stocklist[index * 30];
		profit = profit > stockvalue - min ? profit : stockvalue - min;
		min = min < stockvalue ? min : stockvalue;
	}

	cout << "Max profit is : " << profit << endl;
	
	return 0;
}
