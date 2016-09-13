// Counting Sort and Library Sort

#include <iostream>
#include <array>
#include <vector>

#define SIZE 6

using namespace std;

// Counting sort can be optimized if we keep the min/max values of the given array
// Array<int, 6> -> Sorted Array<int, 6>
std::array<int, SIZE> CountingSort(std::array<int, SIZE> list) {
	unsigned int min, max;
	min = 0;
	max = min;

	// Assuming that all elements are non-negative values
	for (const int& elem : list) {
		if (elem < min)
			min = elem;
		else if (elem > max)
			max = elem;
	}

	std::vector<int> count(max+1, 0);
	for (const int& elem : list) {
		count[elem] = count[elem] + 1;
	}

	unsigned int position = 0;
	for (unsigned int index = min; index <= max; index++) {
		if (count[index] <= 0) {
			continue;
		}

		unsigned int tmp_position = position;
		position += count[index];
		count[index] = tmp_position;
	}

	// Based upon the position, we create an array
	std::array<int, SIZE> sorted_array;
	for (const int& elem : list) {
		sorted_array[count[elem]] = elem;
		count[elem] = count[elem] + 1;
	}

	return sorted_array;
}

// Deciding how much space to create between divisions
// Not yet Implemented
void LibrarySort(std::array<int, SIZE> list) {

}

void PrintElements(std::array<int, SIZE> list) {
	for (const int& elem : list) {
		cout << elem << "\t";
	}

	cout << endl;
}

int main(int argc, char* argv[]) {
	std::array<int, SIZE> a1 = {2, 2, 3, 1, 10, 9};	
	std::array<int, SIZE> a2 = {4, 4, 1, 2, 8, 5};

	// Before Sorting
	cout << "Array #1 (a1) : ";
	PrintElements(a1);
	cout << "Array #2 (a2) : ";
	PrintElements(a2);

	cout << "\t\tSorting the arrays . . ." << endl;
	a1 = CountingSort(a1);
	LibrarySort(a2);

	// After Sorting
	cout << "Array #1 (a1) : ";
	PrintElements(a1);
	cout << "Array #2 (a2) : ";
	PrintElements(a2);
	

	return 0;
}
