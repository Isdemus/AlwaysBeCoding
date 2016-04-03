// Mergesort Implementation
// The main function creates an array with size that is randomly chosen betwen 1 and 100
// Then it will insert random numbers (between 1 and 100) to make the array full.
// * The array can have common elements
// Now it uses an optimized mergesort (that creates one array on stack in each merge() operation)
// It shows before/after calling the mergesort() function!!

#include <iostream>
#include <cstdlib>
#include "time.h"
#include <cmath>
#include <assert.h>
using namespace std;

int random_size(int size) {
	return rand()%size + 1;
}

int* produce_random_array(int size_of_array) {
	int* array = new int[size_of_array];

	for (int m=0; m<size_of_array; m++) {
		int random_number = random_size(size_of_array);
		if (random_number%2) { random_number *= -1; }
		array[m] = random_number;
	}
	
	return array;
}

void print_array(int* array, int size_of_array, string header) {
	cout << "\t\t" << header << endl;
	cout << "\tPrinting array" << endl;
	cout << "\tsize_of_array: " << size_of_array << endl;
	for (int m=0; m<size_of_array; m++) {
		cout << array[m] << " ";
	}
	cout << endl;
	cout << "\tDone" << endl;
}

void show(int array[], int SIZE) {
	for (int m=0; m<SIZE; m++) {
		cout << array[m] << " ";
	}
}

void show2(int* array, int left, int right) {
	for (int i=left; i<=right; i++) {
		cout << array[i] << " ";
	}
}

int* merge(int* array_1, int* array_2, int left, int middle, int right) {
	int start = left;
	int start_2 = middle+1;
	int SIZE = abs(right-left)+1;
	assert(middle < right);
	int fake_array[SIZE];
	int fake_start = 0;

	while (start <= middle && start_2 <= right) {
		if (array_1[start] <= array_2[start_2]) {
			fake_array[fake_start] = array_1[start];
			start += 1;
		}else {
			fake_array[fake_start] = array_2[start_2];
			start_2 += 1;
		}

		fake_start += 1;
	}


	if (start > middle) {
		for (int m=fake_start; m<SIZE; m++) {
			fake_array[m] = array_2[start_2];
			start_2 += 1;
		}
	}else {
		for (int m=fake_start; m<SIZE; m++) {
			fake_array[m] = array_1[start];
			start += 1;
		}
	}

	//overwriting the elements
	fake_start = 0;
	for (int i=left; i<=right; i++) {
		array_1[i] = fake_array[fake_start];
		fake_start += 1;
	}

	return array_1;
}

int* merge_sort(int* array, int left, int right) {
	const int SIZE = abs(right-left)+1;
	if (SIZE == 0) {
		return NULL;
	}else if (SIZE == 1) {
		return array;
	}else if (!SIZE%2) {
		int middle = (right + left - 1) / 2;
		return merge(merge_sort(array, left, middle), merge_sort(array, middle+1, right), left, middle, right);
	}else {
		int middle = (right + left) / 2;
		return merge(merge_sort(array, left, middle), merge_sort(array, middle+1, right), left, middle, right);
	}
}

int main(int argc, char* argv[]) {
	srand(time(0));

	int size_of_array = random_size(100);
	int* random_array_1 = produce_random_array(size_of_array);	

	print_array(random_array_1, size_of_array, "Before the sorting");
	random_array_1 = merge_sort(random_array_1, 0, size_of_array-1);
	print_array(random_array_1, size_of_array, "After the sorting");


	delete[] random_array_1;
	return 0;
}