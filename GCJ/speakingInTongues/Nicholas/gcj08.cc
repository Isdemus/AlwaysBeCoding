/*
Google Code Jam Entrance Test
(Speaking in Tongues: https://code.google.com/codejam/contest/1460488/dashboard)

Used Algorithm Method: ranged for loop, hashmap
Coded by isdemus (May 30 2016)
*/

#include <iostream>
#include <utility>
#include <map>
using namespace std;

typedef unsigned int ui;
/*
std::map<char, char>::operator= (map<char, char>&& old_map) {
  this.reference = std::move(old_map.reference);
  old_map.reference = NULL;
}
*/

void mapping_helper(map<char, char>& translator, const string& hint, const string& answ) {
  for (ui index=0; index<hint.length(); index++)
    translator[hint[index]] = answ[index];

  //return translator
}

int main (int argc, char* argv[]) {
  int cases;
  map<char, char> translator;

  // mapping elements to register
  string hint1, hint2, hint3, answ1, answ2, answ3;
  hint1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
  hint2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  hint3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  answ1 = "our language is impossible to understand";
  answ2 = "there are twenty six factorial possibilities";
  answ3 = "so it is okay if you want to just give up";
  
  // adding mapping elements from the three given sentences.
  //translator = mapping_helper(translator, hint1, answ1);
  //translator = mapping_helper(translator, hint2, answ2);
  //translator = mapping_helper(translator, hint3, answ3);

  mapping_helper(translator, hint1, answ1);
  mapping_helper(translator, hint2, answ2);
  mapping_helper(translator, hint3, answ3);

  // adding the rest mapping elements
  translator['z'] = 'q';

  cin >> cases;
  getline(cin, hint1); 
  for (int c=1; c<=cases; c++) {
    string lineToTranslate, answer = "";
    getline(cin, lineToTranslate);

    // For a given line(string input), it translates to
    for (char ch : lineToTranslate) {
      answer += translator[ch];
    }

    cout << "Case #" << c << ": " << answer << endl;    
  }

  return 0;
}
