#include <iostream>
#include <string>

#define stdoutans(c, answer) std::printf("Case #%d: %d\n", c, answer);

using namespace std;

typedef unsigned int ui;

int main(int argc, char* argv[]) {
  ui cases;
  cin >> cases;
  for (ui c=1; c<=cases; c++) {
    ui numCards, numMoves=0;
    string cardName1, cardName2;
    cin >> numCards;

    cin >> cardName1;

    for (ui card=1; card<=numCards; card++) {
      cin >> cardName2;
      if (strcmp(cardName1.c_str(), cardName2.c_str()) > 0)
        numMoves += 1;
      cardName1 = cardName2;
    }

    stdoutans(c, numMoves);
  }

  return 0;
}
