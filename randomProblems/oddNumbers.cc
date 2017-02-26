#include <iostream>
#include <set>

#define ARRSIZE(array) (sizeof(array) / sizeof(*array))

void PrintArr(int arr[], const int leng)
{
	for (int index = 0; index < leng; index++) {
		if (index < leng - 1) {
			std::cout << arr[index] << " ";
			continue;
		}
		std::cout << arr[index] << std::endl;
	}
}

int main(int argc, char *argv[])
{
	int arr[55];

	int target = 0;
	int times  = 0;
	for (int index = 0; index < ARRSIZE(arr); index++) {
		if (times == 0) {
			target += 1;
			times   = target;
		}
		arr[index] = target;
		times -= 1;
	}

	std::cout << "Printing the array created" << std::endl;
	PrintArr(arr, ARRSIZE(arr));
	std::cout << std::endl;

	// Algorithm to print only the numbers that the arr has odd number of times
	std::set<int> oddset;

	// Using the set, the odd number of times appeared elements will be remained in the set
	for (int element : arr) {
		std::set<int>::iterator it = oddset.find(element);
		if (it != oddset.end()) {
			oddset.erase(it);
			continue;
		}
		oddset.insert(element);	
	}

	// Iterate over the set to print out the remained elements
	std::cout << "Printing the elements that appeared odd number of times" << std::endl;
	for_each(oddset.begin(), oddset.end(), [=](int elem) -> void {
		std::cout << elem << "  ";
	});
	std::cout << std::endl;

	// Same problem, but to print the elements that appeared even number of times
	std::set<int> evenset;

	for (int element : arr) {
		std::set<int>::iterator it = oddset.find(element);
		if (it == oddset.end()) {
			evenset.insert(element);
		}
	}

	std::cout << "Printing the elements that appeared even number of times" << std::endl;
	for_each(evenset.begin(), evenset.end(), [=](int elem) {
		std::cout << elem << "  ";
	});
	std::cout << std::endl;

	return 0;
}
