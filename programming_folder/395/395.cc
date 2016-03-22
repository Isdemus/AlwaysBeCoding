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

bool not_occupied(int x, int y, vector<int> pieces) {
	int number = 10*(x+1) + y+1;
	const int SIZE = pieces.size();
	for (int i=0; i<SIZE; i++) {
		if (pieces[i] == number) {
			return false;
		}
	}

	return true;
}

bool path_clear(int ori_x, int ori_y, int x, int y, vector<int> opposite) {
	const int SIZE = opposite.size();
	if (ori_x == x) { //col path
		int min_ = min(ori_y, y);
		int max_ = max(ori_y, y);
	
		for (int m = min_+1; m < max_; m++) {
			if (!not_occupied(x, m, opposite)) {
				return false;
			}
		}
	}else if (ori_y == y) { //row path
		int min_ = min(ori_x, x);
		int max_ = max(ori_x, x);

		for (int m = min_+1; m < max_; m++) {
			if (!not_occupied(m, y, opposite)) {
				return false;
			}
		}
	}else if (ori_x < x && ori_y < y) { //clean
		int t=ori_y + 1;
		for (int k=ori_x+1; k<x; k++) {
			if (!not_occupied(k, t, opposite)) {
				return false;
			}

			t += 1;
		}
		
	}else if (ori_x > x && ori_y > y) {
		int t=y + 1;
		for (int k=x+1; k<ori_x; k++) {
			if (!not_occupied(k, t, opposite)) {
				return false;
			}
			t += 1;
		}
		
	}else if (ori_x > x && ori_y < y) { //clean
		int t=y - 1;
		for (int k=x+1; k<ori_x; k++) {
			if (!not_occupied(k, t, opposite)) {
				return false;
			}
			t -= 1;
		}
		
	}else { // ori_x < x && ori_y > y
		int t=ori_y - 1;
		for (int k=ori_x+1; k<x; k++) {
			if (!not_occupied(k, t, opposite)) {
				return false;
			}
			t -= 1;
		}
		
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

void check_move(int x_, int y_, vector<int> array, vector<int> pieces, vector<int> opposite, string fn, bool &moved, vector<int> &buffer) {
	int x = x_;
	int y = y_;
	int diff = 0;

	if (fn == "row+") {
			diff = array[y];
			x += diff;
	}else if (fn == "row-") {
			diff = array[y];
			x -= diff;
	}else if (fn == "col+") {
			diff = array[x];			
			y += diff;
	}else if (fn == "col-") {
			diff = array[x];
			y -= diff;
	}else if (fn == "diaL+") {
			diff = array[x+y];

			x += diff;
			y -= diff;
	}else if (fn == "diaL-") {
			diff = array[x+y];

			x -= diff;
			y += diff;
	}else if (fn == "diaR+") {
			diff = array[7-y+x];

			x += diff;
			y += diff;
	}else {
			diff = array[7-y+x];

			x -= diff;
			y -= diff;
	}

	//cout << "ori_x: " << x_ << " ori_y: " << y_ << " x: " << x << " y: " << y << endl;

	if (bounded(x, y) && diff > 0 && not_occupied(x, y, pieces) && path_clear(x, y, x_, y_, opposite)) {
		moved = true;
		buffer.push_back(10 * (x+1) + (y+1));
	}
}


bool possible_move(vector<int> row_array, vector<int> col_array,
			 vector<int> diagL_array, vector<int> diagR_array, vector<int> pieces, vector<int> opposite) {
	const int SIZE = pieces.size();
	int x = zero;
	int y = zero;
	bool moved = false;

	for (int m=0; m<SIZE; m++) {
		x = pieces[m]/10 - 1;
		y = pieces[m]%10 - 1;

		vector<int> buffer;
		check_move(x, y, diagR_array, pieces, opposite, "diagR-", moved, buffer);
		check_move(x, y, col_array, pieces, opposite, "row-", moved, buffer);
		check_move(x, y, diagL_array, pieces, opposite, "diaL-", moved, buffer);
		check_move(x, y, row_array, pieces, opposite, "col-", moved, buffer);
		check_move(x, y, row_array, pieces, opposite, "col+", moved, buffer);
		check_move(x, y, diagL_array, pieces, opposite, "diaL+", moved, buffer);
		check_move(x, y, col_array, pieces, opposite, "row+", moved, buffer);
		check_move(x, y, diagR_array, pieces, opposite, "diaR+", moved, buffer);

		const int SIZE = buffer.size();
		if (SIZE > 1) { sort(buffer.begin(), buffer.end()); }
		for (int m=0; m<SIZE; m++) {
			int num = buffer[m];
			print_move(x, y, num/10 - 1, num%10 - 1);
		}
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
	int times = 0;
	int row = zero;
	int col = zero;

	vector<int> copy_vector(8, 0);
	vector<int> col_array(SIZE_1, zero);
	vector<int> row_array(SIZE_1, zero);
	vector<int> diagR_array(SIZE_2, zero);
	vector<int> diagL_array(SIZE_2, zero);

	//vector<Point> pieces_x, pieces_o;
	vector<int> pieces_x, pieces_o;

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

				/*
				Point p;
				p.row = row;
				p.col = col;
				*/

				if (input == 'X') {
					pieces_x.push_back(10*(row+1) + col+1);
				}else {
					pieces_o.push_back(10*(row+1) + col+1);
				}
			}

			col += 1;
			if (row == SIZE_1 - 1 && col == SIZE_1) {
				if (times > 0) {
					cout << endl;
				}
				cin >> target;
				bool moved = false;
				//vector<vector<int>* > pieces_opposite(8, NULL);
				if (target == 'X') {
				//	make_opposite(pieces_opposite, pieces_o);
					moved = possible_move(row_array, col_array, diagL_array, diagR_array, pieces_x, pieces_o);
				}else {
				//	make_opposite(pieces_opposite, pieces_x);
					moved = possible_move(row_array, col_array, diagL_array, diagR_array, pieces_o, pieces_x);
				}
				row = zero;
				col = zero;

				col_array = copy_vector;
				row_array = copy_vector;
				diagL_array = copy_vector;
				diagR_array = copy_vector;
				pieces_x.clear();
				pieces_o.clear();
				times += 1;
				if (!moved) {
					cout << "No moves are possible" << endl;
				}
			}else if (col == SIZE_1) {
				row += 1;
				col = zero;
			}
		}
	}

	return 0;
}