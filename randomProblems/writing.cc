#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <climits>
using namespace std;

#define intMax INT_MAX;

int main (int argc, char* argv[]) {
	srand(time(0));
	string commonDirPath = "/Users/JUNGJAE/Desktop/git/ABC/randomProblems/input";
	string line;

	// Writing Part
	ofstream fileToWrite (commonDirPath + "/input4.txt", ios::app);
	if (fileToWrite.is_open()) {
		for (int m=50; m>0; m--) { 
			fileToWrite << rand()%intMax + 1;
			fileToWrite << "\n";
			fileToWrite.flush();
		}
	}

	// Reading Part
	ifstream fileToOpen (commonDirPath + "/input4.txt", ios::in);
	if (fileToOpen.is_open()) {
		int m = 1;
		while (getline(fileToOpen, line)) {
			cout << "m: " << m << "  " << line << endl;			
			m += 1;
		}
	}
//		cout << "Wrong in ifstream" << endl;

	fileToWrite.close();
	fileToOpen.close();

	return 0;
}
