#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include <pcrecpp.h>

typedef unsigned int ui;

using namespace std;

int main(int argc, char* argv[]) {

  std::string s;

  std::string emailrule = "(.\\s?){4}((?:골\\s?뱅\\s?이)|엣|에|앳|애)(.+)((?:닷\\s?컴)|(?:다\\s?컴)|(?:닷\\s?넷)|(?:닷\\s?씨\\s?오\\s?점\\s?케\\s?이\\s?오\\s?알\\s?)|(?:다\\s?씨\\s?오\\s?점\\s?케\\s?이\\s?오\\s?알)|(?:메일))";

  if (atoi(argv[1]) == 0) {
    ifstream filetoread (argv[2], ios::in);

    while (getline(filetoread, s)) {
      cout << "original s : " << s << endl;

      // Naming 
      //pcrecpp::RE(emailrule, PCRE_UTF8).GlobalReplace("1: \\1 -- 2: \\2 -- 3: \\3 -- 4: \\4 -- 5: \\5 -- 6: \\6 -- 7: \\7 -- 8: \\8", &s);
      pcrecpp::RE(emailrule, PCRE_UTF8).GlobalReplace("**** \\2 *** \\4", &s);

      // Trimming
      pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &s);
      cout << "new s : " << s << endl;
    }

    filetoread.close();
  } else {
    while (getline(std::cin, s)) {
      cout << "original s : " << s << endl;

      // Naming 
      //pcrecpp::RE(emailrule, PCRE_UTF8).GlobalReplace("1: \\1 -- 2: \\2 -- 3: \\3 -- 5: \\5 -- 6: \\6", &s);
      pcrecpp::RE(emailrule, PCRE_UTF8).GlobalReplace("\\1 **\\3 **\\7 ", &s);

      // Trimming
      pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &s);
      cout << "new s : " << s << endl;
    }
  }

  return 0;
}
