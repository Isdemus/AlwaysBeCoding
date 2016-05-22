#include <iostream>

#define fr(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

typedef long long ll;


template <typename type>
type simpleTmp(type a, type b) { return a > b ? a : b; }


int main (int argc, char* argv[]) {
	int a = 3;
	int b = 4;
	fr(i, 10)
		cout << "The value is: " << simpleTmp(a,b) << endl;

	return 0;
}