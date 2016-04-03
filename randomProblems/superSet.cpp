#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int A[] = {1,2,3,4,5};
	int N = 5;
	int total = 1 << N;
	cout << "total(initial): " << total << endl;
	for (int i=0; i<total; i++) {
		for (int j=0; j<N; j++) {
			if ((i >> j) & 1) {
				cout << "inside: i: " << i << " and j: " << j << endl;
				cout << A[j];
			}
		}
		cout << endl;
	}
	return 0;
}