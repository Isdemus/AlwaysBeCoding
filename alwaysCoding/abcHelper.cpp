// Lib file: abcHelpers.cpp
// Coded by isdemus (updated on 2016 05 01)
// It is a library file that includes helper functions to use in ABC(Always Be Coding) codes.

#include "abcHelper.h"
using namespace std;

void seeding() {
	srand(time(0));
}

int random_size(int size) {
	return rand()%size + 1;
}

int* produce_random_array(int size_of_array) {
	int* array = new int[size_of_array];

	for (int m=0; m<size_of_array; m++) {
		int random_number = random_size(size_of_array);
		if (random_number%2)
			random_number *= -1;
		array[m] = random_number;
	}
	
	return array;
}

void print_header(string header, int extra = -1) {
	if (extra > -1)
		cout << "\t\t" << header << extra << endl;
	else
		cout << "\t\t" << header << endl;
}

void print_array(int* array, int size_of_array, string header) {
	print_header(header + "\n" + "\tPrinting array"
					+ "\tsize_of_array: ", size_of_array);
	for (int m=0; m<size_of_array; m++)
		cout << array[m] << " ";
	cout << endl << "\tDone" << endl;
}

void print_int_vector(vector<int> vec, string header) {
	print_header(header + "\n" + "\tPrinting vector\n" 
					+ "\tsize_of_vector: ", vec.size());
	for (vector<int>::iterator it=vec.begin(); it!=vec.end(); it++)
		cout << *it << endl;
	cout << endl << "\tDone" << endl;
}