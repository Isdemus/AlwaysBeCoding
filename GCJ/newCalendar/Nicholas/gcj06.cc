/*
Google Code Jam Entrance Test
(New Calendar (kor): https://code.google.com/codejam/contest/1403486/dashboard)

Used Algorithm Method: mathematical recursion
Coded by isdemus (May 21 2016)
*/

#include <iostream>
#include <cstdlib>

#define customStdout(a, b) std::cout << "Case #" << a << ": " << b << std::endl;

using namespace std;

typedef long long int lli;
typedef unsigned int ui;

int main (int argc, char* argv[]) {
	lli cases, numMonth, numDaysInMonth, numDaysInWeek;
	cin >> cases;

	// Getting input (3 numbers in a line)
	for (ui c=1; c<=cases; c++) {
		cin >> numMonth >> numDaysInMonth >> numDaysInWeek;

		// initializing the variables to use in each case
		// no longer need colIndicator

		// lli colIndicator
		lli rowIndicator, dayIndicator, currentMonth;
		rowIndicator = dayIndicator = currentMonth = 0;
	
// Even betetr solution - O(1) for large
// O(C) where C is #of cases - way faster than the first solution
// Key: For Version2, we subtract the rest of days to fill from the next month.
//		For Version3, we add the days left from this month to the next month.
// Cases: 1. numDaysInMonth is divisible by numDaysInWeek (ex. 3 28 7)
//		  2. numDaysInMonth will be divisible by numDaysInWeek after some months (ex. )
//		  3. numDaysInMonth will not be divisible at all (ex. 3 11 4)

		do {
			dayIndicator += numDaysInMonth;
			rowIndicator += dayIndicator / numDaysInWeek + (dayIndicator%numDaysInWeek ? 1 : 0);
			//cout << rowIndicator << endl;
			dayIndicator = dayIndicator % numDaysInWeek;
			currentMonth += 1; 
			// We just printed a month (adding the rest days to the next month - no need to care)
		} while (dayIndicator != 0 && currentMonth < numMonth);

		// For case #1 and case #2
		if (currentMonth != numMonth) {
			rowIndicator = rowIndicator * (numMonth / currentMonth);
			numMonth = numMonth % currentMonth;

			// Same Logic for the case #3 above except dayIndicator won't be zero this time
			while (currentMonth < numMonth) {
				dayIndicator += numDaysInMonth;
				rowIndicator += dayIndicator / numDaysInWeek + (dayIndicator%numDaysInWeek ? 1 : 0);
				dayIndicator = dayIndicator % numDaysInWeek;
				currentMonth += 1;
			}
		}

		customStdout(c, rowIndicator);


/*
// better solution - O(N) - Version 2
// O(NC) where C is #of cases - way faster than the first solution
		bool neatEnd = true;
		currentMonth += 1;
		colIndicator = numDaysInWeek - 1;
		while ( currentMonth <= numMonth ) {
			if (currentMonth > 1 && !neatEnd) {
				rowIndicator += 1;
			}

			long long int value = numDaysInWeek - 1 - colIndicator;
			neatEnd = false;

			long long int quotient = (numDaysInMonth-value) / numDaysInWeek;
			long long int remainder = (numDaysInMonth-value) % numDaysInWeek;

			cout << "quotient: " << quotient << " remainder: " << remainder << endl;
			cout << "currentMonth: " << currentMonth << endl;
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
*/

/* This solution takes too much time for a large set of input values.
// O(N^2) -- Version 1
// O(CN^2) where C is #of cases - way faster than the first solution
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
