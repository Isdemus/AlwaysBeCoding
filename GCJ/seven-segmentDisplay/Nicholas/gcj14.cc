/*
Google Code Jam Entrance Test
(seven-segment display: https://code.google.com/codejam/contest/3214486/dashboard)

Used Algorithm Method: 
Coded by isdemus ( 2016)
*/

#include <iostream>
#include <string>
#include <vector>

#define zero  "1111110"
#define one   "0110000"
#define two   "1101101"
#define three "1111001"
#define four  "0110011"
#define five  "1011011"
#define six   "1011111"
#define seven "1110000"
#define eight "1111111"
#define nine  "1111011"

typedef unsigned int ui;

using namespace std;

int main(int argc, char* argv[]) {
  ui cases, records;
  string answer, line;
  cin >> cases;

  for (ui c=1; c<=cases; c++) {
    vector<string> history;
    cin >> records;
    for (ui record=0; record<records; record++) {
      cin >> line;
      cout << "line: " << line << endl;
      history.push_back(line);
    } 

    answer = one;
    printf("Case #%u: %s\n", c, answer.c_str());
  }   

  return 0;
}
