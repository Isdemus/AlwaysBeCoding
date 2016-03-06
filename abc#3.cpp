// abc#3
// implementing stack, queue, vector using an array

#include <iostream>
using namespace std;

/* Basic implementation of stack with integers
   Pre-setting certain amount of the next integers will not be efficient
   So we need an agreement that this arr will not get any interference by others */
class custom_stack {
	private:
		int* arr;
		int* top;
		int size; 
		//is having a capacity variable better than using .size()?

	public:
		custom_stack() {
			arr  = NULL;
			top  = NULL;
			size = 0;
		}

		custom_stack(int value) {
			arr = new int;
			this->push(value);
			top = arr;
			size += 1;
		}

		int peek() {
			if (this->size == 0) {
				return 0;
			} else {
				return *(this->top);
			}
		}

		void push(int data) {
			if (size == 0) {
				this->arr = new int;
				*(this->arr) = data;
				this->top = this->arr;
			} else {
				*(this->arr+size) = data;
				this->top = this->arr+size;
			}
			this->size += 1;
		}

		void pop() {
			if (size > 0) {
				this->top = this->top - 1;
				size -= 1;
			}
		}

		~custom_stack() {
			if (this->size > 0) {
				free(this->arr);
			}
		}
};

void durable_cs_test(custom_stack* cs, void (*f) (custom_stack*, int), int repeat) {
	int initial_data = 10;

	for(int i=0; i<repeat; i++) {
		(*f)(cs, initial_data);
		initial_data += 15;
	}
}

void automatic_cs_test(custom_stack* cs, int initial_data) {
	cs->push(initial_data);
	cs->push(initial_data+5);
	cs->push(initial_data+10);
	cs->pop();
	cout << "value: " << cs->peek() << endl;
}

int main(int argc, char* argv[]) {

	cout << "program begin\n" << endl;

	custom_stack* cs = new custom_stack();
	automatic_cs_test(cs, 5);
	durable_cs_test(cs, &automatic_cs_test, 100000);

	cout << "\nprogram terminate" << endl;

	return 0;
}
