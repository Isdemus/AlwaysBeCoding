#include <iostream>
#define fr(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

typedef long long ll;

class simpleClass {
  public:
    simpleClass () : simpleName (""), simpleSize(0) {};
    simpleClass (string name, int size) : simpleName (name), simpleSize (size) {};
    friend ostream& operator<< (ostream& ost, const simpleClass& sc) {
      ost << sc.simpleName << " : " << sc.simpleSize; return ost;
    }

  private:
    string simpleName;
    unsigned int simpleSize;
};

template <typename type>
type simpleTmp (type a, type b) { return a > b ? a : b; }

template <typename type1, typename type2>
void printValues (type1 first, type2 second) { cout << first << " : " << second << endl; }

template <typename type1, typename type2>
simpleClass* generic_3types (type1 a, type2 b) { return new simpleClass (a, b); }


int main (int argc, char* argv[]) {
	int a = 3;
	int b = 4;
	fr(i, 10)
		cout << "The value is: " << simpleTmp(a,b) << endl;

  printValues ("checking the value", 25);
  simpleClass* sc = generic_3types ("abc", 123);
  cout << *sc << endl;

	return 0;
}
