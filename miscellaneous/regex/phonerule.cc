#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include <pcrecpp.h>

typedef unsigned int ui;

using namespace std;

int main(int argc, char* argv[]) {

  std::string s;

  std::string phonerule = "((?:공\\s?이)|(?:공\\s?오\\s?일)|(?:공\\s?오\\s?삼)|(?:공\\s?삼\\s?이)|(?:공\\s?육\\s?이)|(?:공\\s?륙\\s?이)|(?:공\\s?사\\s?이)|(?:공\\s?오\\s?이)|(?:공\\s?사\\s?사)|(?:공\\s?삼\\s?일)|(?:공\\s?삼\\s?삼)|(?:공\\s?사\\s?삼)|(?:공\\s?사\\s?일)|(?:공\\s?육\\s?삼)|(?:공\\s?륙\\s?삼)|(?:공\\s?육\\s?일)|(?:공\\s?륙\\s?일)|(?:공\\s?오\\s?사)|(?:공\\s?오\\s?오)|(?:공\\s?육\\s?사)|(?:공\\s?륙\\s?삼)|(?:공\\s?일\\s?공)|(?:공\\s?일\\s?일)|(?:공\\s?일\\s?이)|(?:공\\s?일\\s?육)|(?:공\\s?일\\s?륙)|(?:공\\s?일\\s?칠)|(?:공\\s?일\\s?팔)|(?:공\\s?일\\s?구))?(.+)?(\\s?(일|(?:[일|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵]\\s?이)|(?:이\\s?[일|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵])|(?:[일|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵]\\s?이\\s?[일|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵])|삼|사|오|육|륙|칠|팔|공|넷|구|빵)){3,4}에?(.+)?(\\s?(일|(?:[일|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵]\\s?이)|(?:이\\s?[일|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵])|(?:[일|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵]\\s?이\\s?[일|이|삼|사|오|육|륙|칠|팔|공|넷|구|빵])|삼|사|오|육|륙|칠|팔|공|넷|구|빵)){3,4}";

  if (atoi(argv[1]) == 0) {
    ifstream filetoread (argv[2], ios::in);

    while (getline(filetoread, s)) {
      cout << "original s : " << s << endl;

      // Naming 
      pcrecpp::RE(phonerule, PCRE_UTF8).GlobalReplace("\\2 \\5", &s);
      //pcrecpp::RE(phonerule, PCRE_UTF8).GlobalReplace("*** **** **** \\2 \\5", &s);

      // Trimming
      pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &s);
      cout << "new s : " << s << endl;
    }

    filetoread.close();
  } else {
    while (getline(std::cin, s)) {
      cout << "original s : " << s << endl;

      // Naming 
      //pcrecpp::RE(phonerule, PCRE_UTF8).GlobalReplace("1: \\1 -- 2: \\2 -- 3: \\3 -- 5: \\5 -- 6: \\6", &s);
      pcrecpp::RE(phonerule, PCRE_UTF8).GlobalReplace("\\1 **\\3 **\\7 ", &s);

      // Trimming
      pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &s);
      cout << "new s : " << s << endl;
    }
  }

  return 0;
}
