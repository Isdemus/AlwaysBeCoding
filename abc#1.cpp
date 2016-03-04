//ABC #1
//linked list implementation

//INITIAL Plan: basic structure definition

#include <iostream>
using namespace std;

struct list {
	list* next;
	list* prev;
	int data1; 
};

//automated function to build a list
void list_generator(struct list* object, struct list* next, struct list* prev, int data1) {
	object->next = next;
	object->prev = prev;
	object->data1 = data1;
}

int main(int argc, char* argv[]) {
	cout << "program begein" << endl;

	struct list firstObject;
	list_generator(&firstObject, NULL, NULL, 100);

	struct list* secondObject = new list;
	list_generator(secondObject, NULL, NULL, 50);

	struct list* thirdObject = (list*) malloc(sizeof(struct list));
	list_generator(thirdObject, NULL, NULL, 25);

	/* checking area */
	cout << firstObject.data1 << endl;
	cout << secondObject->data1 << endl;
	cout << thirdObject->data1 << endl;

	cout << "program terminated" << endl;

	return 0;
}