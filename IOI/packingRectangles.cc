#if 0
	Problem   : Packing Rectangles
	Reference : http://www.ioinformatics.org/locations/ioi95/contest/tasks/pack.shtml
#endif // Comment

#include <iostream>
#include <list>

#include <cassert>

#define NUMREC   4
#define FAIL     1
#define SUCCESS -1

using namespace std;

void SetZero(unsigned int length[], unsigned int height[], int index) {
	length[index] = -1;
	height[index] = -1;
}

int Try_and_verify(unsigned int length[], unsigned int height[], int blength, int bheight) {
	// Check if any rectangle has higher length side than blength/bheight (easy things to do first)
	// i.e., the rectangle will not be fit, so return FAIL
	for (int rec = 0; rec < NUMREC; rec++) {
		if ((length[rec] > blength && length[rec] > bheight) ||
				(height[rec] > blength && height[rec] > bheight)) {
			return FAIL;
		}
	}

	for (int rec = 0; rec < NUMREC; rec++) {
		if (length[rec] < 0) { continue; } // Already used rectangle
		int leng = length[rec];
		int heig = height[rec];

		blength -= leng;
		bheight -= heig;

		if (blength > 0)		

	}

	return SUCCESS;
}


int main(int argc, char* argv[]) {
	unsigned int length[NUMREC + 1], height[NUMREC + 1], area;
	unsigned int min_area, max_side, max_index; 

	for (int rec = 0; rec < NUMREC; rec++) {
		cin >> length[rec] >> height[rec];
		area = length[rec] * height[rec];
		min_area += area;

		// Making sure height[i] >= length[i] for all i = {0, 1, 2, 3}
		if (length[rec] > height[rec]) {
			length[rec] = length[rec] ^ height[rec];
			height[rec] = length[rec] ^ height[rec];
			length[rec] = length[rec] ^ height[rec];
		}
	}

	// A queue that will be used to store every candidate to attempt
	queue<pair<int, unsigned int>> try_buffer;

	for (;;) {
		assert(try_buffer.empty()); // Abort if not tried all
		queue<pair<unsigned int, unsigned int>> answer_queue;

		for (int rec = 0; rec <NUMREC; rec++) {
			if (min_area % height[rec] == 0)
				try_buffer.push(make_pair(rec, height[rec]));
			if (min_area % length[rec] == 0)
				try_buffer.push(make_pair(rec, length[rec]));
		} 

		while (!try_buffer.empty()) {
			auto core = try_buffer.front();
			try_buffer.pop();

			int index   = core.first;
			int blength = core.second;
			int bheight = min_area / blength;

			if (length[core.first] == blength) {
				bheight -= height[index];
			} else {
				bheight -= length[index];
			}
			SetZero(length, height, index);
			if (Try_and_verify(length, height, blength, bheight) == SUCCESS) {
				cout << blength << " " << bheight << endl;
			}
		}

		if (!answer_queue.empty()) {
			auto pack_rectangle = answer_queue.front();
			cout << pack_rectangle.first * pack_rectangle.second << endl;
			break;
		}

		// Repeating the whole process to find the minimum area
		min_area += 1;
	}

	// Printing every possible answer
	while (!answer_queue.empty()) {
		cout << answer_queue.front().first 
				<< " "
				<< answer_queue.front().second() 
				<< endl;
		answer_queue.pop();
	}

	return 0;
}
