//ABC #2
//Linked List -> Class (development)

#include <iostream>
using namespace std;

enum request_t {next, prev, first, last, data};

//Assumption: List will be used with a pointer
class List {
	private:
		List* next;
		List* prev;
		List* first;
		List* last;
		string* data;

	public:
		List() { //default constructor
			this->next  = NULL;
			this->prev  = NULL;
			this->first = NULL;
			this->last  = NULL;
			this->data = NULL;
		}

		void request_setter(enum request_t type, List* list = NULL, string* data = NULL) {
			switch(type) {
				case 0:
					this->next = list;
				case 1:
					this->prev = list;
				case 2:
					this->first = list;
				case 3:
					this->last = list;
				case 4:
					this->data = data;

				default:
					break;
			}
		}

		List* request_getter(enum request_t type) {
			switch(type) {
				case 0:
					return this->next;
				case 1:
					return this->prev;
				case 2:
					return this->first;
				case 3:
					return this->last;

				default:
					return NULL;
			} 
		}

		string* get_data() {
			return this->data;
		}

		void print_data() {
			cout << "next: " << this->data << endl;
		}

		~List() {
			free(this->data);
			free(this);
		}
};

int main(int argc, char* argv[]) {
	cout << "program begein" << endl;

	List* firstClass = new List;
	List* secondClass = new List;
	enum request_t type = request_t::next;
	enum request_t type2 = request_t::next;
	firstClass->request_setter(type2, secondClass);

	
	if(firstClass->request_getter(type) == NULL) {
		cout << "wrong" << endl;
	}



	/* checking area */

	cout << "program terminated" << endl;

	return 0;
}