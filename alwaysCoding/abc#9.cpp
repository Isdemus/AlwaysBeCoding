// c++11 rvalue reference lab and move constructor and move assignment operator
#include <iostream>
#include <utility>

using namespace std;

class rvalueClass {
  public:
    rvalueClass () : SIZE_t (0), className("None") {};
    rvalueClass (string name) : SIZE_t (1), className (name) {};
    
    // Basic copy construtor
    rvalueClass (const rvalueClass& old) : SIZE_t (old.SIZE_t), className (old.className) {};

    // move constructor
    rvalueClass (rvalueClass&& old) {
      this->SIZE_t = std::move(old.SIZE_t);
      this->className = std::move(old.className);
      old.SIZE_t = 0;
      old.className = "";
    }

    void printValues() {
      cout << this->SIZE_t << " : " << this->className << endl;
    }

  private:
    unsigned int SIZE_t;
    string className;
};

rvalueClass getRvalueClass() {
  return rvalueClass("Nicky");
}

string getName() {
  return "NickRValue";
}

// Using generic function to overcome the limitation of rvalue refernece
template <typename a>
void printReference3 (a str) {
  cout << str << endl;
  str = str + "abc";
  cout << str << endl;
}

void printReference (string& str) {
  cout << str << endl;
  str = str + "abc";
  cout << str << endl;
}

void printReference2 (string&& str) {
  cout << str << endl;
  str = str + "abc";
  cout << str << endl;
}

int main (int argc, char* argv[]) {
  string str1 ("Nick");
  printReference(str1);
  printReference2(getName());
  printReference3(str1);
  printReference3(getName());

  cout << endl << "Testing rvalueClasses in the order (r1, r2, r3, r4)" << endl;
  rvalueClass* r1 = new rvalueClass("Nick");
  rvalueClass* r2 = r1;
  rvalueClass  r3 = *r1;
  // move constructor
  rvalueClass  r4(getRvalueClass());

  r1->printValues();
  r2->printValues();
  r3.printValues();
  r4.printValues();

  return 0;
}
