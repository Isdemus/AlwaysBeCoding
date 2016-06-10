#include <iostream>
#include <string>
#include <map>

#define stdoutans(c, answer) std::printf("Case #%d: %s\n", a, answer);

using namespace std;

typedef unsigned int ui;

int main(int argc, char* argv[]) {
  ui cases;
  cin >> cases;
  for (ui c=1; c<=cases; c++) {
    bool gameCompleted = true;
    string status = "Draw";
    
    

    stdoutans(c, status.c_str());
  }

  return 0;
}
