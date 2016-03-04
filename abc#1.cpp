//ABC #1
//linked list implementation

//INITIAL Plan: basic structure definition

#include <iostream>
using namespace std;

typedef struct list{
	struct list* next;
	struct list* prev;
	int data1;
} List;

//automated function to build a list
void list_generator(List* object, List* next, List* prev, int data1) {
	object->next = next;
	object->prev = prev;
	object->data1 = data1;
}

int main(int argc, char* argv[]) {
	cout << "program begein" << endl;

	List firstObject;
	list_generator(&firstObject, NULL, NULL, 100);

	List* secondObject = new List;
	list_generator(secondObject, NULL, NULL, 50);

	List* thirdObject = (List*) malloc(sizeof(List));
	list_generator(thirdObject, NULL, NULL, 25);

	/* produce 50 lists with a value */


	/* checking area */
	cout << firstObject.data1 << endl;
	cout << secondObject->data1 << endl;
	cout << thirdObject->data1 << endl;

	cout << "program terminated" << endl;

	return 0;
}