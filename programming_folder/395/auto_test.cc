#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	srand(time(0));
	int count = 0;
	int count_O = 0;
	int count_X = 0;
	int random;
	char ch;

	ofstream ofs ("test.txt", ofstream::out);
	for (int m=0; m<3; m++) {
		while (count < 65) {

			random = rand()%3;
			if (random == 0) {
				ch = 'X';
				count_X += 1;
			}else if (random == 1) {
				ch = '.';
			}else {
				ch = 'O';
				count_O += 1;
			}
			count += 1;

			if (count%8) {
				ofs << ch;
			}else {
				ofs << ch;
				ofs << endl;
				if (count == 64) {
					char target;
					if (rand()%2 == 0) {
						target = 'X';
					}else {
						target = 'O';
					}
					ofs << target;
					ofs << endl;
					count += 1;
				}
			}
		}
		count = 0;
		count_O = 0;
		count_X = 0;
	}

	ofs.close();

	return 0;
}