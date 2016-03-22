// #395

#include <iostream>
#include <vector>
#include <algorithm>
#define zero 0
using namespace std;

typedef struct point {
	int row;
	int col;
}Point;

void print_move(int x, int y, int x_2, int y_2) {
	char ch1 = x + 'A';
	char ch2 = x_2 + 'A';

	cout << ch1 << y+1 << "-" << ch2 << y_2+1 << endl;
}

bool path_clear(int ori_x, int ori_y, int x, int y, vector<vector<int>* > opposite) {
	cout << "ori_x: " << ori_x << endl;
	cout << "ori_y: " << ori_y << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	if (ori_x == x) { //col path
		int min_ = min(ori_y, y);
		int max_ = max(ori_y, y);

		vector<int>* vec = opposite[x];

		for (int m = min_+1; m < max_; m++) {
			for (int k=0; k<vec->size(); k++) {
				if (vec->at(k) == m) {
					return false;
				}
			}
		}
	}else if (ori_y == y) { //row path
		int min_ = min(ori_x, x);
		int max_ = max(ori_x, x);

		for (int m = min_+1; m < max_; m++) {
			vector<int>* vec = opposite[m];
			for (int k=0; k<vec->size(); k++) {
				if (vec->at(k) == y) {
					return false;
				}
			}
		}
	}else if (ori_x < x && ori_y < y) { //clean
		int t=ori_y + 1;
		for (int k=ori_x+1; k<x; k++) {
			vector<int>* vec = opposite[k];
			for (int m=0; m<vec->size(); m++) {
				if (vec->at(m) == t) {
					return false;
				}
			}
			t += 1;
		}
		/*
	}else if (ori_x > x && ori_y > y) {
		int t=y + 1;
		for (int k=x+1; k<ori_x; k++) {
			vector<int>* vec = opposite[k];
			if (vec == NULL) {return true;}
			for (int m=0; m<vec->size(); m++) {
				if (vec->at(m) == t) {
					return false;
				}
			}
			t += 1;
		}
		*/
	}else if (ori_x > x && ori_y < y) { //clean
		int t=y - 1;
		for (int k=x+1; k<ori_x; k++) {
			if (k < 0 || t < 0) {return true;}
			vector<int>* vec = opposite[k];
			for (int m=0; m<vec->size(); m++) {
				if (vec->at(m) == t) {
					return false;
				}
			}
			t -= 1;
		}
		/*
	}else { // ori_x < x && ori_y > y
		int t=ori_y - 1;
		for (int k=ori_x+1; k<x; k++) {

			vector<int>* vec = opposite[k];
			if (vec == NULL) {return true;}

			for (int m=0; m<vec->size(); m++) {
				if (vec->at(m) == t) {
					return false;
				}
			}
			t -= 1;
		}
		*/
	}

	return true;
}

bool bounded(int x, int y) {
	if (x < 0 || x > 7) {
		return false;
	}else if (y < 0 || y > 7) {
		return false;
	}

	return true;
}

void check_move(int x_, int y_, vector<int> array, vector<vector<int>* > opposite, string fn, bool &moved) {
	int x = x_;
	int y = y_;
	int diff = 0;
	int index = 0;
	if (fn == "row+") {
			x += array[y];
			diff = array[y];
	}else if (fn == "row-") {
			x -= array[y];
			diff = array[y];
	}else if (fn == "col+") {
			y += array[x];
			diff = array[x];
	}else if (fn == "col-") {

			y -= array[x];
			diff = array[x];

	}else if (fn == "diaL+") {
			index = x + y;
			diff = array[index];

			x += array[index];
			y -= array[index];
	}else if (fn == "diaL-") {
			index = x + y;
			diff = array[index];

			x -= array[index];
			y += array[index];
	}else if (fn == "diaR+") {
			index = 7 - y + x;
			diff = array[index];

			x += array[index];
			y += array[index];
	}else {
			index = 7 - y + x;
			diff = array[index];

			x -= array[index];
			y -= array[index];
	}

	if (bounded(x, y) && diff > 0 && path_clear(x, y, x_, y_, opposite)) {
		moved = true;
		print_move(x_, y_, x, y);
	}
}


bool possible_move(vector<int> row_array, vector<int> col_array,
			 vector<int> diagL_array, vector<int> diagR_array, vector<Point> pieces, vector<vector<int>* > opposite) {
	const int SIZE = pieces.size();
	int x = zero;
	int y = zero;
	bool moved = false;

	for (int m=0; m<SIZE; m++) {
		x = pieces[m].row;
		y = pieces[m].col;

		check_move(x, y, diagR_array, opposite, "diagR-", moved);
		check_move(x, y, col_array, opposite, "row-", moved);
		check_move(x, y, diagL_array, opposite, "diaL-", moved);
		check_move(x, y, row_array, opposite, "col-", moved);
		check_move(x, y, row_array, opposite, "col+", moved);
		check_move(x, y, diagL_array, opposite, "diaL+", moved);
		check_move(x, y, col_array, opposite, "row+", moved);
		check_move(x, y, diagR_array, opposite, "diaR+", moved);
	}

	return moved;
}

void make_opposite(vector<vector<int>* > &opposite, vector<Point> pieces) {
	const int SIZE = pieces.size();
	int x = zero;
	int y = zero;
	for (int m=0; m<SIZE; m++) {
		Point p = pieces[m];
		x = p.row;
		y = p.col;

		if (opposite[x] == NULL) {
			vector<int>* vec = new vector<int>();
			vec->push_back(y);
			opposite[x] = vec;
		}else {
			vector<int>* vec = opposite[x];
			vec->push_back(y);
		}
	}
}

void print_vector(vector<Point> vec) {
	for (int m=0; m<vec.size(); m++) {
		cout << "(" << vec[m].row << "," << vec[m].col << ")" << endl;
	}
}

void print_vector_2(vector<int> vec) {
	for (int m=0; m<vec.size(); m++) {
		cout << "value of m: " << m << " and the value: " << vec[m] << endl;
	}
}

int main(int argc, char* argv[]) {
	char input, target;
	bool finished = false;

	const int SIZE_1 = 8;
	const int SIZE_2 = 15;
	const int diagR_offset = 7;

	int row = zero;
	int col = zero;

	vector<int> copy_vector(8, 0);

	vector<int> col_array(SIZE_1, zero);
	vector<int> row_array(SIZE_1, zero);
	vector<int> diagR_array(SIZE_2, zero);
	vector<int> diagL_array(SIZE_2, zero);
	//int col_array[SIZE_1] = {};
	//int row_array[SIZE_1] = {};
	//int diagR_array[SIZE_2] = {};
	//int diagL_array[SIZE_2] = {};

	vector<Point> pieces_x, pieces_o;

	while (!finished) {
		cin >> input;
		if (cin.eof()) {
			finished = true;
		}else {
			if (input == 'X' || input == 'O') {
				row_array[row] += 1;
				col_array[col] += 1;
				diagR_array[diagR_offset - col + row] += 1;
				diagL_array[row+col] += 1;

				Point p;
				p.row = row;
				p.col = col;

				if (input == 'X') {
					pieces_x.push_back(p);
				}else {
					pieces_o.push_back(p);
				}
			}

			col += 1;
			if (row == SIZE_1 - 1 && col == SIZE_1) {
				cin >> target;
				bool moved = false;
				vector<vector<int>* > pieces_opposite(8, NULL);
				if (target == 'X') {
					make_opposite(pieces_opposite, pieces_o);
					moved = possible_move(row_array, col_array, diagL_array, diagR_array, pieces_x, pieces_opposite);
				}else {
					make_opposite(pieces_opposite, pieces_x);
					moved = possible_move(row_array, col_array, diagL_array, diagR_array, pieces_o, pieces_opposite);
				}
				row = zero;
				col = zero;

				col_array = copy_vector;
				row_array = copy_vector;
				diagL_array = copy_vector;
				diagR_array = copy_vector;
				pieces_x.clear();
				pieces_o.clear();

				if (!moved) {
					cout << "No moves are possible" << endl;
				}
			}else if (col == SIZE_1) {
				row += 1;
				col = zero;
			}
		}
	}


	cout << "successful" << endl;
	cout << "diag Right" << endl;
	print_vector_2(diagR_array);

	cout << "diag Left" << endl;
	print_vector_2(diagL_array);
	
	cout << "row" << endl;
	print_vector_2(row_array);

	cout << "col" << endl;
	print_vector_2(col_array);

	cout << "target: " << target << endl;
	cout << "points: " << endl;
	if (target == 'O') {
		print_vector(pieces_o);
	}else {
		print_vector(pieces_x);
	}



	return 0;
}