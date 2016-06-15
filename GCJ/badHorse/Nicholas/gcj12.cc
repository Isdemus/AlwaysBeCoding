/*
Google Code Jam Entrance Test
(Bad Horse: https://code.google.com/codejam/contest/2933486/dashboard)

Used Algorithm Method: Simple Logic
Coded by isdemus (June 12 2016)
*/

#include <iostream>
#include <map>

#define stdoutans(c, answer) std::printf("Case #%d: %s\n", c, answer);

using namespace std;

enum custom_bool { out, in, hold };

typedef unsigned int ui;
typedef enum custom_bool ecb;

int main(int argc, char* argv[]) {
	ui cases;
	cin >> cases;

	for (ui c=1; c<=cases; c++) {
		map<string, ecb> groupA;
		map<string, ecb> groupB;
		map<string, string> pair;

		string name1, name2, line, answer= "Yes";
		ui troublesome;

		cin >> troublesome;

		for (ui trouble=0; trouble<troublesome; trouble++) {
			cin >> name1;
			cin >> name2;

			//pair[name1] = name2;
			//pair[name2] = name1;

			if ((groupA[name1] == hold && groupA[name2] == hold) || 
            (groupB[name1] == hold && groupB[name2] == hold)) {
				answer = "No";
			} else if (groupA[name1] != out && groupA[name2] != out) {
        if (groupB[pair[name1]] == hold || groupB[pair[name2]] == hold) {
//          cout << "Unable to swap" << endl;
          answer = "No"; 
        } else if (groupB[pair[name1]] == hold) {
				  groupA[name1] = hold;
				  groupB[name2] = hold;
        } else {
          groupA[name2] = hold;
          groupB[name1] = hold;
        }
      } else if (groupB[name1] != out && groupB[name2] != out) {
        if (groupA[pair[name1]] == hold || groupA[pair[name2]] == hold) {
//          cout << "unable to swap" << endl;
          answer = "No";
        } else if (groupA[pair[name1]] == hold) {
          groupA[name2] = hold;
          groupB[name1] = hold;
        } else {
          groupA[name1] = hold;
          groupB[name2] = hold;
        }
			} else if (groupA[name1] != out) {
				groupA[name1] = hold;
				groupB[name2] = hold;
			} else if (groupB[name1] != out) {
				groupB[name1] = hold;
				groupA[name2] = hold;
			} else if (groupA[name2] != out) {
				groupA[name2] = hold;
				groupB[name1] = hold;
			} else if (groupB[name2] != out) {
				groupB[name2] = hold;
				groupA[name1] = hold;
			} else {
				groupA[name1] = in;
				groupB[name2] = in;
			}

      pair[name1] = name2;
      pair[name2] = name1;

			while (answer == "No" && trouble<troublesome) {
				getline(cin, line);
				trouble += 1;
			}
		}

//		cout << groupA[Dead_Bowie] << endl;

		stdoutans(c, answer.c_str());
	}

	return 0;
}
