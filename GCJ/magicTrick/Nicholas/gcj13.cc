/*
Google Code Jam Entrance Test
(Magic Trick: https://code.google.com/codejam/contest/2974486/dashboard)

Used Algorithm Method: simple parsing, simple logic
Coded by isdemus (June 23nd 2016)
*/

#include <iostream>
#include <string>

#define stdoutans(c, answer) std::printf("Case #%u: %s\n", c, answer);

typedef unsigned int ui;
using namespace std;

// readVoidCards: unsigned int -> (void)
// A function to read cards that won't be used in calculation.
void readVoidCards(ui times) {
  string voidLine;
  getline(cin, voidLine); // getline for End of Line for Cin

  for (ui index=0; index<times; index++)
    getline(cin, voidLine);
}

int main(int argc, char* agrv[]) {
  ui cases, card, selection, match, answerCard;
  ui collection[4];
  string answer;
  cin >> cases;
  
  for (ui c=1; c<=cases; c++) {
    cin >> selection;

    // Read the cards before the selected cards
    readVoidCards(selection-1);   

    // Read the four selected cards and save them in an array
    for (ui index=0; index<4; index++) {
      cin >> card;
      collection[index] = card;
    }

    // Read the cards after the selected cards
    readVoidCards(4-selection);
    
    cin >> selection;
    
    // Read the cards before the selected cards in second round
    readVoidCards(selection-1);

    // mapping the cards in a new row to the ones selected before
    match = 0;
    for (ui index=0; index<4; index++) {
      cin >> card;
      for (ui candidate : collection) {
        if (card == candidate) {
          answerCard = card;
          match += 1;
        }
      }
    }

    // Read the rest cards
    readVoidCards(4-selection);

    // Simple logic to decide the case!
    if (match > 1)
      answer = "Bad magician!";
    else if (match == 0)
      answer = "Volunteer cheated!";
    else
      answer = to_string(answerCard);
      
    stdoutans(c, answer.c_str());
  }

  return 0;
}
