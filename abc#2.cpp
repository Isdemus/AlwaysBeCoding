//ABC #2
//Linked List -> Class (development)

#include <iostream>
using namespace std;

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

		List* get_next() {
			return this->next;
		}

		List* get_prev() {
			return this->prev;
		}

		List* get_first() {
			return this->first;
		}

		List* get_last() {
			return this->last;
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



	/* checking area */

	cout << "program terminated" << endl;

	return 0;
}