/*
Google Code Jam Entrance Test
(Tic-Tac-Toe-Tomek: https://code.google.com/codejam/contest/2270488/dashboard)

Used Algorithm Method: Simple math + logic
Coded by isdemus (June 12 2016)
*/

#include <iostream>
#include <sstream>
#include <string>
#include <map>

#define stdoutans(c, answer) std::printf("Case #%d: %s\n", c, answer);

using namespace std;

typedef unsigned int ui;

// changeStatus: char, string& -> (void)
// Simply changing the reference value of the string.
void changeStatus(char winner, string& status) {
	stringstream ss;
	ss << winner;
	ss << " Won";
	getline(ss, status);
}

// columnCheck: const map<ui, char> , string& -> bool
// When there is no winning condition met in rowCheck, it is called to check
// the winning conditions in columns.
bool columnCheck(map<ui, char> guide_book, string& status) {
	char _ch, _ch2;
	bool colCheck;

  	for (ui col=0; col<4; col++) {
  		_ch2 = ' ';
  		colCheck = true;

  		for (ui row=0; row<4; row++) {
  			_ch = guide_book[row*10+col];

  			if (_ch == '.') {
  				colCheck = false;
  				break;
  			} else if (colCheck && _ch2 == ' ' && _ch != 'T') {
  				_ch2 = _ch;
  			} else if (colCheck && _ch != 'T' && _ch != _ch2) {
  				colCheck = false;
  				break;
  			}
  		}

  		if (colCheck) {
			changeStatus(_ch2, status);
			return true;
  		}
  	}	

  	return false;
}

// diagCheck: map<ui, char>, string& -> bool
// It is called when the columnCheck() returned false (=no winner found),
// It is checking the winning condition in two diagonals (left/right)
bool diagonalCheck(map<ui, char> guide_book, string& status) {
	char _ch, _ch2 = ' ', _ch3 = ' ';
  	bool diag1Check = true, diag2Check = true;

  	for (ui diag=0; diag<4; diag++) {
  		if (diag1Check) {
  			_ch = guide_book[diag*10+diag];

  			if (_ch == '.')
  				diag1Check = false;
  			else if (_ch2 == ' ' && _ch != 'T')
  				_ch2 = _ch;
  			else if (_ch != 'T' && _ch != _ch2)
  				diag1Check = false;
  		}

  		if (diag2Check) {
  			_ch = guide_book[diag*10+(3-diag)];

  			if (_ch == '.')
  				diag2Check = false;
  			else if (_ch3 == ' ' && _ch != 'T')
  				_ch3 = _ch;
  			else if (_ch != 'T' && _ch != _ch3)
  				diag2Check = false;
  		}
  	}

  	if (diag1Check) {
  		changeStatus(_ch2, status);
  		return true;
  	} else if (diag2Check) {
  		changeStatus(_ch3, status);
  		return true;
  	} else {
  		return false;
  	}
}

// main function to run our program
int main(int argc, char* argv[]) {
  ui cases;
  cin >> cases;
  for (ui c=1; c<=cases; c++) {
    char _ch, _ch2;
    bool rowCheck, gameCompleted = true;
    string line, status = "Draw";
  	map<ui, char> guide_book;

  	for (ui row=0; row<4; row++) {
  		// Row checking while getting input values
  		_ch2 = ' ';
  		rowCheck = true;

  		for (ui col=0; col<4; col++) {
  			cin >> _ch;
  			guide_book[row*10+col] = _ch;

  			if (_ch == '.') {
  				rowCheck = false;
  				gameCompleted = false;
  			} else if (rowCheck && _ch2 == ' ' && _ch != 'T') {
  				_ch2 = _ch;
  			} else if (rowCheck && _ch != 'T' && _ch != _ch2) {
  				rowCheck = false;
  			}
  		}

  		if (rowCheck) {
  			changeStatus(_ch2, status);

  			while (row < 4) {
  				getline(cin, line);
  				row += 1;
  			}
  			break;
  		}
  	}

  	// Column checking
  	bool colCheck = true;
  	if (!rowCheck)
  		colCheck = columnCheck(guide_book, status);

  	// Diagonal checking
  	bool diagCheck = true;
  	if (!colCheck)
  		diagCheck = diagonalCheck(guide_book, status);

  	if (!diagCheck && !gameCompleted)
  		status = "Game has not completed";
    stdoutans(c, status.c_str());
  }

  return 0;
}
