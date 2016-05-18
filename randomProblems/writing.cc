#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <climits>
#include <map>
#include <string>
using namespace std;

#define intMax INT_MAX;


// bAddition: String, String -> String
// For any high numbers, this addition function can be used if given two numbers as string variables.
// P.S. For an addition of more than two numbers, choose a recursive way to calculate
string bAddition (string number1, string number2) {
        string* resultString = &number2;
        int number1_index    = number1.length()-1;
        int number2_index    = number2.length()-1;
        unsigned int upgrade          = 0;
        int size              = number2_index;

        /* Display two numbers */
        //cout << " " + spacingFormat(number1, 80) << endl;
        //cout << "+" + spacingFormat(number2, 80) << endl;
        if (number1.length() > number2.length()) {
                resultString = &number1;
                size         = number1_index;
        }

        for (size; size>=0; size--) {
                unsigned int digit1 = 0;
                unsigned int digit2 = digit1;

                if (number1_index >= 0)
                        digit1 = (unsigned int)number1[number1_index] - 48;
                if (number2_index >= 0)
                        digit2 = (unsigned int)number2[number2_index] - 48;

                int sum = digit1 + digit2 + upgrade;
                if (sum >= 10) {
                        upgrade = 1;
                        sum = sum%10;
                }else
                        upgrade = 0;

                (*resultString)[size] = (char)(sum + 48);

                number1_index -= 1;
                number2_index -= 1;
        }

        if (upgrade)
                *resultString = "1" + *(resultString);

        return *resultString;
}

int main (int argc, char* argv[]) {
	srand(time(0));
	string commonDirPath = "/Users/JUNGJAE/Desktop/git/ABC/randomProblems/input";
	string line;
	bool setup = false;

	map<unsigned int, string> positive_map;
	map<unsigned int, string> negative_map;

	for (int index=4; index<6; index++) {

		string fileName1 = "/input" + to_string(index) + "_positive.txt";
		string fileName2 = "/input" + to_string(index) + "_negative.txt"; 
		
		cout << "filename: " << fileName1 << " filename2: " << fileName2 << endl;

		ifstream filePositive ( commonDirPath + fileName1 );
		ifstream fileNegative ( commonDirPath + fileName2 );

		if (filePositive.is_open() && fileNegative.is_open()) {

			getline(filePositive, line);
			getline(fileNegative, line);

			for (int lineNumber=0; lineNumber<14; lineNumber++) {
				getline(filePositive, line);
				if (!setup) {
					positive_map[lineNumber] = line;
					getline(fileNegative, line);
					negative_map[lineNumber] = line;
				}else {
					if (lineNumber%2)
						positive_map[lineNumber] = bAddition(line, positive_map[lineNumber]);
					getline(fileNegative, line);
					if (lineNumber%2)
						negative_map[lineNumber] = bAddition(line, negative_map[lineNumber]);
				}		
			}
	
			setup = true;
			filePositive.close();
			fileNegative.close();
		}else {
			cerr << "something went wrong to open positive/negative files" << endl;
		}
	}


	// displaying the both positive and negative maps
	printf("Date\tPositive\tNegative\n");
	for (int size=0; size<positive_map.size(); size++) {
		if(size%2) {
			printf("\t%s\t%s\n", positive_map[size].c_str(), negative_map[size].c_str());
		}else
			printf("%s", positive_map[size].c_str());
	}

	// writing the result into a file called input4_5_result.txt
	ofstream fileToWrite (commonDirPath + "/input_4_5_result.txt", ios::app);
	if (fileToWrite.is_open()) {
		string header = "Date\tPositive\tNegative\n";
		fileToWrite << header;
		for (int size=0; size<positive_map.size(); size++) {
			if (size%2) {
				fileToWrite << "\t" + positive_map[size] + "\t" + negative_map[size] + "\n";
			}else {
				fileToWrite << positive_map[size];
			}	

			fileToWrite.flush();
		}

		fileToWrite.close();
	}else {
		cerr << "something is wrong to open a file" << endl;
	}

	fileToWrite.close();
/*
	index = 0;
	cout << endl;
	while (negative_map[index] != "") {
		cout << "index: " << index << "  negative_map: " << negative_map[index] << endl;
		index += 1;
	}
*/
/*
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
*/


	return 0;
}
