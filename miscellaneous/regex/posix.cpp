#include <iostream>
#include <regex.h>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  std::string line;
  regex_t re;
  std::string regexp = ".*let me (play|listen to)[[:space:]]+(.*)+[[:space:]]+by{0,1}[[:space:]]+(.*)";
  regexp = ".*(listen to|play)[[:space:]]+(.+)[music|song|songs]*[[:space:]]*(played|sang|sung)*[[:space:]]*by{0,1}[[:space:]]+(.+)[[:alnum:]]*";
  regexp = ".*(listen to|play)[[:space:]]+(.+)([[:space:]]| music| song| songs)+[[:space:]]*([[:blank:]]|played by|by|sung by)+[[:space:]]+(.+)[[:alnum:]]*";

//  regexp = ".*(listen to|play)[[:space:]]+(.+)[[:space:]]*(music|song|songs)*";
//[[:space:]]*[played|sang|sung]*[[:space:]]*by[[:space:]]+(.+)[[:alnum:]]*";

  int status = regcomp(&re, regexp.c_str(), REG_EXTENDED);
  if (status != 0) {
    cout << "ERROR to compile a regex" << endl;
    return 1;
  }

  while(getline(cin, line)) {
    const char* newLine = line.c_str();
    const int maxMatch = 15;
    regmatch_t pieces[maxMatch];

    int matched = regexec(&re, newLine, maxMatch, pieces, 0);
    if (matched) {
      cout << "No Match" << endl;
    } else {
      for (unsigned index = 0; index < maxMatch; index++) {
        if (pieces[index].rm_so > -1)
          cout << "Match[" + to_string(index) + "] : " + line.substr(pieces[index].rm_so, pieces[index].rm_eo - pieces[index].rm_so) << endl;
      }
    }
  }

}
