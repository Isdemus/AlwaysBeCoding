//ABC #2
//Linked List -> Class (development)

#include <iostream>
using namespace std;

enum request_t {next, prev, first, last, data};
enum request_t_2 {width, length, area};

//Assumption: List will be used with a pointer
class List {
	private:
		List* next;
		List* prev;
		List* first;
		List* last;

	protected:
		string* data;

	public:
		List() { //default constructor
			this->next  = NULL;
			this->prev  = NULL;
			this->first = NULL;
			this->last  = NULL;
			this->data  = NULL;
		}

		List* next_getter() {
			return this->next;
		}

		void request_setter(enum request_t type, List* list = NULL, string* data = NULL) {
			switch(type) {
				case 0:
					this->next = list;
					break;
				case 1:
					this->prev = list;
					break;
				case 2:
					this->first = list;
					break;
				case 3:
					this->last = list;
					break;
				case 4:
					this->data = data;
					break;

				default:
					break;
			}
		}

		List* request_getter(enum request_t type) {
			switch(type) {
				case 0:
					return this->next;
					break;
				case 1:
					return this->prev;
					break;
				case 2:
					return this->first;
					break;
				case 3:
					return this->last;
					break;

				default:
					return NULL;
					break;
			} 
		}

		string* get_data() {
			return this->data;
		}

		void print_data() {
			if (this->data == NULL) {
				cout << "trying to dereference NULL pointer" << endl;
			} else {
				cout << "data: " << *(this->data) << endl;
			}
		}

		~List() {
			free(this->data);
			free(this);
		}
};

typedef struct point {
	int x_crd;
	int y_crd;
	
	point(int x, int y) {
		this->x_crd = x;
		this->y_crd = y;
	}
} Point;

// Assumption: Box is used with a pointer
// No setter -> constant boxes
class Box : public List {
	private:
		int width;
		int length;
		int area;
		union {
			bool square;
			Point* center;
		}extra;

	public:
		//default constructor
		Box(int width, int length) : List() {
			this->width = width;
			this->length = length;
			this->area = this->calculate_area(width, length);
			is_square();
		}

		Point* get_point() {
			if (this->width != this->length) {
				return this->extra.center;
			} else {
				return NULL;
			}
		}

		bool get_square() {
			if (this->width == this->length) {
				return this->extra.square;
			} else {
				return false;
			}
		}

		int request_getter(enum request_t_2 type) {
			switch(type) {
				case 0:
					return this->width;
					break;
				case 1:
					return this->length;
					break;
				case 2:
					return this->area;
					break;
				default:
					return 0;
					break;
			}
		}

		int calculate_area(int width, int length) {
			return width * length;
		}

		void is_square() {
			if (this->width == this->length) {
				this->extra.square = true;
			} else {
				Point* pt = new Point(width/2, length/2);
				this->extra.center = pt;
			}
		}

		~Box() {
			//we can also add a check (if) condition to check if it is a pointer before freeing
			if(this->width == this->length) { free(this->extra.center); }
			free(this->data);
			free(this);
		}
};

void boolean_interpretor(bool value) {
	cout << "value: " << value << endl;
	if (value == true) {
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}
}

int main(int argc, char* argv[]) {
	cout << "program begein" << endl;

	/* List declarations */
	List* firstClass = new List();
	List* secondClass = new List();
	enum request_t type1 = request_t::next;
	enum request_t type2 = request_t::data;
	string str = "lala";
	firstClass->request_setter(type1, secondClass);
	firstClass->request_setter(type2, NULL, &str);

	/* Box declarations */
	//enum request_t_2 type3 = request_t_2::area;
	Box* first_Box = new Box(5,10);
	Box* second_Box = new Box(5,5);

	/* producing 50 lists to connect */
	List* first = NULL;
	List* last  = NULL;
	List* prev  = NULL;
	string initial_data = "a  ";
	enum request_t type4 = request_t::data;
	enum request_t type5 = request_t::prev;
	enum request_t type6 = request_t::next;
	enum request_t type7 = request_t::first;
	enum request_t type8 = request_t::last;
	enum request_t_2 type9 = request_t_2::area;


	for (int i=0; i<50; i++) {
		string* str = new string();
		*str = initial_data;
		List* randomList = new List();
		randomList->request_setter(type4, NULL, str);
		initial_data += "a  ";

		if (i==0) { first = randomList; }
		else if (i==49) { last = randomList; }

		randomList->request_setter(type7, first);
		randomList->request_setter(type8, last);

		if (prev != NULL) {
			randomList->request_setter(type5, prev);
			prev->request_setter(type6, randomList);
		}

		prev = randomList;
	}

	/* producing 50 boxes to connect */
	Box* firstBox = NULL;
	Box* lastBox  = NULL;
	Box* prevBox  = NULL;

	int initial_width = 1;
	int initial_length = 10;

	for (int i=0; i<50; i++) {
		Box* randomBox = new Box(initial_width, initial_length);

		if (i==0) { firstBox = randomBox; }
		else if(i==49) { lastBox = randomBox; }

		randomBox->request_setter(type7, firstBox);
		randomBox->request_setter(type8, lastBox);

		if (prevBox != NULL) {
			randomBox->request_setter(type5, prevBox);
			prevBox->request_setter(type6, randomBox);
		}

		prevBox = randomBox;
		initial_width += 4;
		initial_length += 2;
	}


	/* checking area */

	//checking 50 lists designed with class (all linked)
	while (first != last) {
		first->print_data();
		first = first->request_getter(type6);
	}

	if (first == last)
		first->print_data();

	//checking 50 Boxes designed with class (all linked)
	while (firstBox != lastBox) {
		int area = firstBox->request_getter(type9);
		cout << "area: " << area << endl;
		firstBox = (Box*) firstBox->next_getter();
	}

	if (firstBox == lastBox) {
		int area = firstBox->request_getter(type9);
		cout << "area: " << area << endl;
	}

	cout << "program terminated" << endl;

	return 0;
}