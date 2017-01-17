#if 0
	Problem   : Packing Rectangles
	Reference : http://www.ioinformatics.org/locations/ioi95/contest/tasks/pack.shtml
#endif // Comment

#include <iostream>
#include <queue>
#include <list>

#include <cassert>

#define NUMREC   4
#define FAIL     1
#define SUCCESS -1

#define ITER for (int rec = 0; rec < NUMREC; rec++)

using namespace std;

void SetZero(unsigned int length[], unsigned int height[], int index) {
	length[index] = -1;
	height[index] = -1;
}

template<typename T>
void Swap(T &first, T &second) {
	first = first ^ second;
	second = first ^ second;
	first = first ^ second;
}

#if 0
void Swap(int &blength, int &bheight) {
	blength = blength ^ bheight;
	bheight = blength ^ bheight;
	blength = blength ^ bheight;
}
#endif

/*
 * A boolean function that will return either SUCCESS/FAIL representing all the four rectangles
 * can be packed and enclosed by the biggest rectangle with blength and bheight
 */
int Try_and_verify(unsigned int length[], unsigned int height[], int &blength, int &bheight) {
	// Check if any rectangle has higher length side than blength/bheight (easy things to do first)
	// i.e., the rectangle will not be fit, so return FAIL
	for (int rec = 0; rec < NUMREC; rec++) {
		if ((length[rec] > blength && length[rec] > bheight) ||
				(height[rec] > blength && height[rec] > bheight)) {
			return FAIL;
		}
	}

	if (blength > bheight) Swap(blength, bheight);
	list<pair<unsigned int, unsigned int>> extra_spaces;

	// Find and stack them up for any rectangle that has a length/height equal to the blength
	for (int rec = 0; rec < NUMREC; rec++) {
		if (height[rec] <= 0) continue;
		if (height[rec] == blength) {
			if (bheight < length[rec]) return FAIL;

			bheight -= length[rec];
			SetZero(length, height, rec);
			if (blength > bheight) Swap(blength, bheight);
		}
	}

	// Find and stack them up for any rectangle that has a length/height longer than the blength
	for (int rec = 0; rec < NUMREC; rec++) {
		if (height[rec] <= 0) continue;
		if (height[rec] > blength && bheight > height[rec]) { // The rectangle has to be stacked 
//			if (bheight < length[rec]) return FAIL;
			if (length[rec] < blength)
				extra_spaces.push_back(make_pair(blength - length[rec], height[rec]));
			bheight -= height[rec];
			SetZero(length, height, rec);
			if (blength > bheight) Swap(blength, bheight);
		}
	}

	// The rest should be able to be fit into the extra_space elements
	for (int rec = 0; rec < NUMREC; rec++) {
		if (length[rec] <= 0) continue; // Already used rectangle
		for (auto space : extra_spaces) {
			if ((space.first >= length[rec]) && (space.second >= height[rec])) {
				space.first = space.first - length[rec];
				space.second = space.second - height[rec];
				SetZero(length, height, rec);
				if (space.first > space.second) Swap(space.first, space.second);
			}
		}
	}

	// If there is any thing left, it's not possible to pack every rectangle
	for (int rec = 0; rec < NUMREC; rec++) {
		if (length[rec] > 0 || height[rec] > 0) return FAIL;
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
	queue<pair<unsigned int, unsigned int>> answer_queue;

	for (;;) {
		cout << "Current min area : " << min_area << endl;
		if (min_area > 40) break;
		assert(try_buffer.empty()); // Abort if not tried all

		for (int rec = 0; rec < NUMREC; rec++) {
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

			if (length[index] == blength) {
				bheight -= height[index];
			} else {
				bheight -= length[index];
			}
			SetZero(length, height, index);
			cout << "blength : " << blength << " & bheight : " << bheight << endl;
			if (Try_and_verify(length, height, blength, bheight) == SUCCESS) {
				answer_queue.push(make_pair(blength, bheight));
			}
		}

		// Printing out the minimum area of the biggest enclosing rectangle
		if (!answer_queue.empty()) {
			auto pack_rectangle = answer_queue.front();
			cout << pack_rectangle.first * pack_rectangle.second << endl;
			break;
		}

		// Repeating the whole process to find the minimum area
		min_area += 1;
	}

	// Printing out every possible length and height of the enclosing rectangle
	while (!answer_queue.empty()) {
		auto answer = answer_queue.front();
		cout << answer.first 
				<< " "
				<< answer.second 
				<< endl;
		answer_queue.pop();
	}

	return 0;
}
