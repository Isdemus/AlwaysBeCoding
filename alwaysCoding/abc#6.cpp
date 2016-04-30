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

int partition(int* array, int start, int end) {
	int pivot = (start + end) / 2;
	int middleValue = array[pivot];

	int left = start; int right = end;

	while(left <= right) {
		while (middleValue > array[left]) left++;
		while (middleValue < array[right]) right--;

		if (left <= right) {
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	}

	return left;

}

void quicksort(int* array, int left, int right) {
	int index = partition(array, left, right);
	if (left < index - 1) {
		quicksort(array, left, index-1);
	}

	if (index < right) {
		quicksort(array, index, right);
	}
}

int main(int argc, char* argv[]) {
	srand(time(0));
	int SIZE = rng(100);
	SIZE = 8;
	int* array = new int[SIZE];

	fill_the_array(array, SIZE);
	print_array(array, SIZE, "Before using our quicksort");
	quicksort(array, 0, SIZE-1);
	print_array(array, SIZE, "After using our quicksort");

	delete[] array;
	return 0;
}