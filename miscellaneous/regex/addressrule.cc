#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include <pcrecpp.h>

typedef unsigned int ui;

using namespace std;

int main(int argc, char* argv[]) {

  std::string s;

  std::string addressrule = "(.+[시|도])(.+(시|군|구))*(.+(읍|면))?(.+(로|동|층|호|번|지|(?:번지)))*";

  if (atoi(argv[1]) == 0) {
    ifstream filetoread (argv[2], ios::in);

    while (getline(filetoread, s)) {
      cout << "original s : " << s << endl;

      // Naming 
      //pcrecpp::RE(addressrule, PCRE_UTF8).GlobalReplace("1: \\1 -- 2: \\2 -- 3: \\3 -- 4: \\4 -- 5: \\5 -- 6: \\6 -- 7: \\7 -- 8: \\8", &s);
      pcrecpp::RE(addressrule, PCRE_UTF8).GlobalReplace("\\1 **\\3 **\\7 ", &s);

      // Trimming
      pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &s);
      cout << "new s : " << s << endl;
    }

    filetoread.close();
  } else {
    while (getline(std::cin, s)) {
      cout << "original s : " << s << endl;

      // Naming 
      //pcrecpp::RE(addressrule, PCRE_UTF8).GlobalReplace("1: \\1 -- 2: \\2 -- 3: \\3 -- 5: \\5 -- 6: \\6", &s);
      pcrecpp::RE(addressrule, PCRE_UTF8).GlobalReplace("\\1 **\\3 **\\7 ", &s);

      // Trimming
      pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &s);
      cout << "new s : " << s << endl;
    }
  }

  return 0;
}
