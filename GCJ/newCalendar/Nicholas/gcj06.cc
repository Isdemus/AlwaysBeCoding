/*
Google Code Jam Entrance Test
(New Calendar (kor): https://code.google.com/codejam/contest/1403486/dashboard)

Used Algorithm Method: basic logic and iostream 
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
	}

	return 0;
}
