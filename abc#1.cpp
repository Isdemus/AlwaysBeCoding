//ABC #1
//linked list implementation

//INITIAL Plan: basic structure definition

#include <iostream>
using namespace std;

struct list {
	list *next;
	list *prev;
	int data1; 
};

int main(int argc, char* argv[]) {
	cout << "program begein" << endl;

	list firstObject;
	firstObject.next = NULL;
	firstObject.prev = NULL;
	firstObject.data1 = 100;

	cout << firstObject.data1 << endl;

	cout << "program terminated" << endl;

	return 0;
}