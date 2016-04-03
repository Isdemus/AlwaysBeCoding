//quicksort implementation

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int rng(int upper_bound) {
	return rand()%upper_bound + 1;
}

void fill_the_array(int* array, int SIZE) {
	int number = 0;
	for (int m=0; m<SIZE; m++) {
		number = rng(SIZE);
		if (number%2) { number *= -1; }
		array[m] = number;
	}
}

void print_array(int* array, int SIZE, string str) {
	cout << str << endl;
	const int size = SIZE;
	for (int m=0; m<size; m++) {
		cout << *(array+m) << " ";
	}
	cout << endl;
}

void quick_sort(int* array, int left, int right) {
	if (array != NULL) { //always good to check if the pointer is NULL
		int middle = (right + left) / 2;
		int start_l = left;
		int start_r = right;
		int temp = 0;
		int temp2 = 0;
		cout << endl;

		for (int m=left; m<=right; m++) {
			cout << *(array+m) << " ";
		}
		cout << endl;
		cout << "left: " << left-left << " right: " << right-left << " middle: " << middle-left << endl;
		
		//cout << "right: " << right << endl;
		while (start_l <= start_r) {
			while (array[start_l] < array[middle]) start_l += 1;
			while (array[start_r] > array[middle]) start_r -= 1;

			cout << "start_l: " << start_l-left << " start_r: " << start_r-left << endl;

			for (int m=left; m<=right; m++) {
				cout << *(array+m) << " ";
			}
			cout << endl;

			if (start_l <= start_r) { //if (array[start_l] > array[start_r]) {
				// cout << "pivot (middle: " << middle << ") : " << array[middle] << endl;
				// cout << "changing array[" << start_l - left << "]" << ": " << array[start_l]
				// 	 << " and array[" << start_r-left << "]" << ": " << array[start_r] << endl;
				temp = array[start_l];
				temp2 = array[start_r];
				array[start_l] = temp2;
				array[start_r] = temp;
				start_l += 1;
				start_r -= 1;


				for (int m=left; m<=right; m++) {
					cout << *(array+m) << " ";
				}
				cout << endl;
					}
		}

		if (left < start_r) {
			// cout << "first if" << endl;
			// cout << "left: " << left-left << " right: " << right-left << endl;
			// cout << "start_l: " << start_l-left << " start_r: " << start_r-left << endl;


			quick_sort(array, left, start_r);
		}
		if (right > start_l-1) {
			// cout << "second if" << endl;
			// cout << "left: " << left-left << " right: " << right-left << endl;
			// cout << "start_l: " << start_l-left << " start_r: " << start_r-left << endl;


			quick_sort(array, start_l, right);
		}
	}
}

int main(int argc, char* argv[]) {
	srand(time(0));
	int SIZE = rng(100);
	SIZE = 8;
	int* array = new int[SIZE];

	fill_the_array(array, SIZE);
	print_array(array, SIZE, "Before using our quicksort");
	quick_sort(array, 0, SIZE-1);
	print_array(array, SIZE, "After using our quicksort");

	delete[] array;
	return 0;
}