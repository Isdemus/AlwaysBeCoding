#if 0
	Problem   : Packing Rectangles
	Reference : http://www.ioinformatics.org/locations/ioi95/contest/tasks/pack.shtml
#endif // Comment

#include <iostream>
#include <list>

#define NUMREC 4

using namespace std;

void SetZero(unsigned int *length, unsigned int *height, int index) {
	length[index] = -1;
	height[index] = -1;
}

int main(int argc, char* argv[]) {
	unsigned int length[NUMREC + 1], height[NUMREC + 1], area;
	unsigned int min_area = 0, max_side = 0, max_index; 

	for (int rec = 0; rec < NUMREC; rec++) {
		cin >> length[rec] >> height[rec];
		area = length[rec] * height[rec];
		min_area += area;

		if (length[rec] > height[rec]) {
			length[rec] = length[rec] + height[rec];
			height[rec] = length[rec] - height[rec];
			length[rec] = length[rec] - height[rec];
		}
		
		if (length[rec] > max_side) {
			max_side = length[rec];
			max_index = rec;
		}
	}

	// Finding the minimum area that is divisible by the max_side
	while (min_area % max_side == 0)	min_area += 1;

	length = max_side;
	height = min_area / length;

	// The biggest rectangle of the four
	height -= height[max_index];
	SetZero(length, height, max_index);

	
	
		
	
	

	return 0;
}
