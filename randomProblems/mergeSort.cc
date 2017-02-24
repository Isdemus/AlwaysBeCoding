#include <iostream>

#define ARRLENG(array) (sizeof(array) / sizeof(array[0]))

void PrintArr(const int arr[], const int leng) {
	for (int index = 0; index < leng; index++) {
		if (index < leng - 1) {
			std::cout << arr[index] << "\t";
			continue;
		}
		std::cout << arr[index] << std::endl;
	}
}

void Mergesort(int arr[], int left, int right) {
	if (left > right) {
		std::cerr << "Error in Mergesort" << std::endl;
		exit(EXIT_FAILURE);
	} else if (left == right) {
		return;
	}
	int center = (left + right) / 2;
	Mergesort(arr, left, center);
	Mergesort(arr, center + 1, right);

	// Merging two sorted arrays
	int reference[right - left + 1];
	for (int index = left; index <= right; index++) {
		reference[index - left] = arr[index];
//		PrintArr(reference, right + 1);
	}

	int arr_index = left;
	int left_arr_index = left;
	int right_arr_index = center + 1;
	while ((left_arr_index <= center) && (right_arr_index <= right)) {
		if (reference[left_arr_index - left] < reference[right_arr_index - left]) {
			arr[arr_index] = reference[left_arr_index - left];
			left_arr_index += 1;
		} else {
			arr[arr_index] = reference[right_arr_index - left];
			right_arr_index += 1;
		}
		arr_index += 1;
	}

	if (left_arr_index <= center) { // If we used every element of the right arr, copy the rest
		for (; arr_index <= right; arr_index++, left_arr_index++) {
			arr[arr_index] = reference[left_arr_index - left];
		}
	}
}

int main(int argc, char *argv[]) {
	int arr[] = {5, 4, 3, 2, 1};

	std::cout << "Before MergeSort" << std::endl;
	PrintArr(arr, ARRLENG(arr));
	Mergesort(arr, 0, 4);
	std::cout << "After MergeSort" << std::endl;
	PrintArr(arr, ARRLENG(arr));

	int arr2[] = {-5, 3, 1, -2, 10, 8};

	std::cout << "Before MergeSort" << std::endl;
	PrintArr(arr2, ARRLENG(arr2));
	Mergesort(arr2, 0, 5);
	std::cout << "After MergeSort" << std::endl;
	PrintArr(arr2, ARRLENG(arr2));

	return 0;
}
