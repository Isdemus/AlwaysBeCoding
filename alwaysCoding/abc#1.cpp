//ABC #1
//linked list implementation

//INITIAL Plan: basic structure definition

#include <iostream>
#include <string>
using namespace std;

enum month_t {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

union data {
	int int_data;
	char char_data;
	bool bool_data;
};

typedef struct list{
	struct list* next;
	struct list* prev;
	struct list* first;
	struct list* last;
	union data list_data;
	enum month_t month;

	list() { //default constructor
		this->next = NULL;
		this->prev = NULL;
	}

	//assumption: list is a pointer with malloc use
	~list() {
		free(this);
	}
} List;

//automated function to build a list
void list_generator(List* object, int data, enum month_t month) {
	object->list_data.int_data = data;
	object->month = month;
}

int main(int argc, char* argv[]) {
	cout << "program begein" << endl;

	//List firstObject;
	//list_generator(&firstObject, 100, jan);

	List* secondObject = new List;
	list_generator(secondObject, 50, feb);

	List* thirdObject = (List*) malloc(sizeof(List));
	list_generator(thirdObject, 25, mar);

	/* produce 50 lists with a value */
	int initial_month = 0;
	int initial_data  = 1;
	struct list* first = NULL;
	struct list* last  = NULL;
	struct list* previous = NULL;
	for(int i=0; i<50; i++) {
		List* randomObject = new List;
		list_generator(randomObject, initial_data, (enum month_t) initial_month);
		if(i==0) { first = randomObject; }
		else if(i==49) { last = randomObject; }

		randomObject->first = first;
		randomObject->last  = last;

		if(previous != NULL) {
			randomObject->prev = previous;
			previous->next = randomObject;
		}

		previous = randomObject;
		if(initial_month==11) { initial_month = 0; }
		else { initial_month += 1; }
		initial_data += 1;
	}


	/* checking area */
	cout << secondObject->list_data.int_data << endl;
	cout << thirdObject->list_data.int_data << endl;

	/* linked list checking area */
	while(first != last) {
		cout << first->list_data.int_data << endl;
		first = first->next;
	}
	if(first == last) {	cout << first->list_data.int_data << endl; }

	cout << "program terminated" << endl;

	return 0;
}