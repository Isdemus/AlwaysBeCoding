
// Description: The generator tricks the RNG algorithm to randomly select numbers.
// After repeatedly picking numbers, it checks if the number is strong (statiscally more likely than other numbers)
// Otherwise, begin the process from the very beginning

// Goal: Trying to generate six winning numbers, although lottery numbers are not based upon statistics.

// Current Version: 
//			Past winning numbers are not yet stored.
// 			Statiscal conditions are not designed nor built yet. 
//			Need to trick the RNG by seeding the time multiple times.
// Coded by isdemus (2016)

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <map>
using namespace std;

vector<int> return_array(vector<int> &number_array) {
	number_array.reserve(50);
	for(int i=0; i<50; i++) {
		if(i%2 == 0) {
			number_array[i] = 1;
		}
	}
	number_array[49] = 500;
	return number_array;
}

//Printing out the elements in the vector data structure
void print_vector(vector<int>* vectorInstance) {
	for (int i=0; i<vectorInstance->size(); i++) {
		cout << vectorInstance->at(i) << "\tat number: " << i+1 << endl;
	}
}

void clear_vector(vector<int>* vectorInstance) {
	for (int i=0; i<vectorInstance->size(); i++) {
		vectorInstance->at(i) = 0;
	}
}

//finding max value of the vector
int find_max_vector(vector<int>* vectorInstance) {
	int max = vectorInstance->at(0);
	int max_index = 0;
	for (int i=1; i<vectorInstance->size(); i++) {
		if (vectorInstance->at(i) > max) {
			max = vectorInstance->at(i);
			max_index = i;
		}
	}

	return max_index;
}

//Stat-approach to pick a best likely number
void stat_1000_numbers(vector<int>* vectorInstance) {
	int limit = 10000;
	int number;

	clear_vector(vectorInstance);
	cout << "clear" << endl;
	
	while (limit > 0) {
		number = rand()%49;
		vectorInstance->at(number) += 1;
		limit -= 1;
	}
}

bool isItAlreadyIn(int potentialNumber, vector<int>* lotteryNumbers) {
	for (int i=0; i<lotteryNumbers->size(); i++) {
		if (lotteryNumbers->at(i) == potentialNumber) {
			return true;
		}
	}

	return false;
}

void pickWinningNumbers(vector<int>* vectorInstance, vector<int>* &lotteryNumbers) {
	bool complete = false;
	do {
		stat_1000_numbers(vectorInstance);
		
		int potentialNumber = find_max_vector(vectorInstance) + 1;

		cout << "potentialNumber: " << potentialNumber << endl;

		if (!isItAlreadyIn(potentialNumber, lotteryNumbers)) {
			lotteryNumbers->push_back(potentialNumber);
		}else {
			cout << "failing a process" << endl;
			vector<int>* temp = lotteryNumbers;
			lotteryNumbers = new vector<int>();
			free(temp);
		}
		cout << "process step finish" << endl;

		if (lotteryNumbers->size() >= 6) { complete = true; }
	} while(!complete);
}

int main(int argc, char* argv[]) {

	srand(time(0));
	//int randomNumber = rand()%1700 + 100;

	//cout << randomNumber << endl;

	cout << "Lotto Simulation Program Begin" << endl;
	for (int i =0; i<30; i++) { cout << "-"; }
	cout << endl << "creating an array to count for 49 numbers" << endl;

	vector<int>* scoreBoard = new vector<int>(49, 0);
	vector<int>* lotteryNumbers = new vector<int>();

//	stat_1000_numbers(scoreBoard);
	//print_vector(scoreBoard);
//	cout << find_max_vector(scoreBoard) << endl;
	pickWinningNumbers(scoreBoard, lotteryNumbers);
	print_vector(lotteryNumbers);


	/* map testing
	vector< map<char, bool> > vec;
	map<char, bool> map_1;

	map_1['c'] = true;

	cout << map_1['c'] << endl;
	cout << map_1['d'] << endl;
	cout << (int)'a' << endl;
	cout << (char)97 << endl;

	*/

	return 0;
}