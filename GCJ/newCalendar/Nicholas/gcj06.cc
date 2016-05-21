/*
Google Code Jam Entrance Test
(New Calendar (kor): https://code.google.com/codejam/contest/1403486/dashboard)

Used Algorithm Method: mathematical recursion
Coded by isdemus (May 21 2016)
*/

#include <iostream>
using namespace std;

int main (int argc, char* argv[]) {
	unsigned int cases, numMonth, numDaysInMonth, numDaysInWeek;
	cin >> cases;

	// Getting input (3 numbers in a line)
	for (unsigned int c=1; c<=cases; c++) {
		cin >> numMonth;
		cin >> numDaysInMonth;
		cin >> numDaysInWeek;

		// initializing the variables to use in each case
		unsigned int rowIndicator = 0;
		unsigned int colIndicator = rowIndicator; // all zero
		unsigned int dayIndicator = colIndicator; // all zero
		unsigned int currentMonth = dayIndicator; // all zero
		
// better solution
// O(NC) where c is #of cases - way faster than the first solution
		bool neatEnd = true;
		currentMonth += 1;
		colIndicator = numDaysInWeek - 1;
		while ( currentMonth <= numMonth ) {
			if (currentMonth > 1 && !neatEnd) {
				rowIndicator += 1;
			}

			unsigned value = numDaysInWeek - 1 - colIndicator;
			neatEnd = false;

			unsigned int quotient = (numDaysInMonth-value) / numDaysInWeek;
			unsigned int remainder = (numDaysInMonth-value) % numDaysInWeek;

			//cout << "quotient: " << quotient << " remainder: " << remainder << endl;
			//cout << "currentMonth: " << currentMonth << endl;
			rowIndicator += quotient + 1;
			colIndicator = remainder - 1;
			if (remainder == 0) {
				colIndicator = numDaysInWeek - 1;
				neatEnd = true;
				rowIndicator -= 1;
			}
			currentMonth += 1;
		}	

                cout << "Case #" << c << ": " << rowIndicator << endl;






/* This solution takes too much time for a large set of input values.
		dayIndicator += 1; // first day in the calendar is at [0,0]
		currentMonth += 1;

		// stopping condition <- writing every given month
		do {
			dayIndicator += 1;

                        if (dayIndicator > numDaysInMonth) {
                                currentMonth += 1;
                                dayIndicator = 1;
                        }

			if (colIndicator == numDaysInWeek-1) {
				colIndicator = 0;
				rowIndicator += 1;
			}else {
				colIndicator += 1;
				if (currentMonth > 1 && dayIndicator == 1)
					rowIndicator += 1;
			}

		}while( currentMonth <= numMonth );

		// Careful: the last day earned one more rowIndicator, so no need to deduct
		cout << "Case #" << ": " << rowIndicator << endl;
*/ //first solution
	}

	return 0;
}
