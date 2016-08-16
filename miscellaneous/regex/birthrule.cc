#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include <pcrecpp.h>

typedef unsigned int ui;

using namespace std;

int main(int argc, char* argv[]) {
  ifstream filetoread ("test2.txt", ios::in);

  std::string s = "생년월일은 팔 칠 공 오일 칠네이요";

  std::string pattern0 = "[일|이|삼|사|오|육|륙|칠|팔|구|공|넷|빵]";
  std::string pattern = "[^일|^이|^삼|^사|^오|^육|^륙|^칠|^팔|^구|^공|^넷|^빵]";
  std::string pattern1 = "((?:이천)|천)\\s?([^[천|이|구|팔|칠|육|륙|오|사|삼]*)\\s?(?:[구|팔|칠|육|륙|오|사|삼|이]?\\s?백?)\\s?([^[천|구|팔|칠|육|륙|오|사|삼|이|십]*)\\s?(?:[구|팔|칠|육|륙|오|사|삼|이]?\\s?십?)\\s?([^[일|구|팔|칠|육|륙|오|사|삼|이]*)\\s?[구|팔|칠|육|륙|오|사|삼|이|일]?\\s?년"; 
  std::string pattern1_5 = "[구|륙|이|삼|사|오|육|칠|팔|오]?\\s?십?\\s?(.+)*\\s?[구|륙|일|이|삼|사|오|육|칠|팔|오]\\s?년";
  std::string pattern2 = pattern1 + "[십|시]{0,1}[구|륙|일|이|삼|사|오|육|칠|팔|공|오]\\s*월\\s*(" + pattern + "*)\\s*[구|륙|일|이|삼|사|오|육|칠|팔|공|오|넷]\\s?십?[일|이|삼|사|오|육|륙|칠|팔|구]]?\\s?일\\s?";

  std::string pattern3 = "십?\\s?[구|륙|일|이|삼|사|오|육|칠|팔|공|오]\\s?월\\s?(" + pattern + "*)\\s?[구|륙|일|이|삼|사|오|육|칠|팔|공|오|넷]\\s?[십일|십이|십삼|십사|십오|십육|십륙|십칠|십팔|십구]*\\s?일\\s?";


  while (getline(filetoread, s)) {
    cout << "original s : " << s << endl;

    // ~십 ~년
    pcrecpp::RE(pattern1_5, PCRE_UTF8).GlobalReplace("**년 \\1", &s); 
    pcrecpp::RE(pattern1, PCRE_UTF8).GlobalReplace("**년 \\2 \\3 \\4", &s); 
    // ~월 ~일
    pcrecpp::RE(pattern3, PCRE_UTF8).GlobalReplace(" **월 **일 \\1", &s);
    // General
   pcrecpp::RE(pattern0 + "(" + pattern + "*)" + pattern0 + "(" + pattern + "*)" + pattern0 + "(" + pattern + "*)" + pattern0 + "(" + pattern + "*)" + pattern0 + "(" + pattern + "*)" + pattern0, PCRE_UTF8).GlobalReplace("**년 **월 **일 \\1 \\2 \\3 \\4 \\5", &s);



    // Trimming
    pcrecpp::RE("\\s{2,}", PCRE_UTF8).GlobalReplace(" ", &s);
    cout << "new s : " << s << endl;
  }

  return 0;
}
