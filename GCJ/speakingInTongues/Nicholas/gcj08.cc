/*
Google Code Jam Entrance Test
(Speaking in Tongues: https://code.google.com/codejam/contest/1460488/dashboard)

Used Algorithm Method: ranged for loop, hashmap
Coded by isdemus (May 30 2016)
*/

#include <iostream>
#include <map>
using namespace std;

typedef unsigned int ui;

int main (int argc, char* argv[]) {
  int cases;
  map<char, char> translator;
  string hint1, hint2, hint3, answ1, answ2, answ3;
  hint1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
  hint2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  hint3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  answ1 = "our language is impossible to understand";
  answ2 = "there are twenty six factorial possibilities";
  answ3 = "so it is okay if you want to just give up";
  
  for (ui index=0; index<hint1.length(); index++) 
    translator[hint1[index]] = answ1[index];
  for (ui index=0; index<hint2.length(); index++)
    translator[hint2[index]] = answ2[index];
  for (ui index=0; index<hint3.length(); index++)
    translator[hint3[index]] = answ3[index];

  translator['z'] = 'q';
  translator[' '] = ' ';

  cin >> cases;
  getline(cin, hint1); 
  for (int c=1; c<=cases; c++) {
    string lineToTranslate, answer = "";
    getline(cin, lineToTranslate);

    for (char ch : lineToTranslate) {
      answer += translator[ch];
    }

    cout << "Case #" << c << ": " << answer << endl;    
  }

  return 0;
}
