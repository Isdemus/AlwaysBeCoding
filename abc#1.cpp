//ABC #1
//linked list implementation

//INITIAL Plan: basic structure definition

#include <iostream>
#include <string>
using namespace std;

enum month_t {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

union data {
	int int_data;
	//string string_data;
	char char_data;
	bool bool_data;
};

typedef struct list{
	struct list* next;
	struct list* prev;
	union data list_data;
	enum month_t month;
} List;

//automated function to build a list
void list_generator(List* object, List* next, List* prev, int data1, enum month_t month) {
	object->next = next;
	object->prev = prev;
	object->list_data.int_data = data1;
	object->month = month;
}

int main(int argc, char* argv[]) {
	cout << "program begein" << endl;

	List firstObject;
	list_generator(&firstObject, NULL, NULL, 100, jan);

	List* secondObject = new List;
	list_generator(secondObject, NULL, NULL, 50, feb);

	List* thirdObject = (List*) malloc(sizeof(List));
	list_generator(thirdObject, NULL, NULL, 25, mar);

	/* produce 50 lists with a value */

	/* checking area */
	cout << firstObject.list_data.int_data << endl;
	cout << secondObject->list_data.int_data << endl;
	cout << thirdObject->list_data.int_data << endl;


	cout << "program terminated" << endl;

	return 0;
}