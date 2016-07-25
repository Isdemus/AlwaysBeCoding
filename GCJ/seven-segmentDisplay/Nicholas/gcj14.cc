/*
Google Code Jam Entrance Test
(seven-segment display: https://code.google.com/codejam/contest/3214486/dashboard)

Used Algorithm Method: 
Coded by isdemus ( 2016)
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

typedef unsigned int ui;

void normalizing(int& index) {
  if (index < 0) {
    index = 10 - abs(index%10);
  }
}

void resetting(bool *broken, const ui& leng) {
  for (ui index=0; index<leng; index++) {
    broken[index] = false;
  }
}

int main(int argc, char* argv[]) {
  ui cases;
  std::string lights[10] = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};
  std::cin >> cases;

  for (ui c=1; c<=cases; c++) {
    ui displays;
    std::string answer, display;
    std::vector<std::string> container;
    std::vector<std::string> answerContainer;

    std::cin >> displays;

    // Because it needs to get the input anyways, we'll separate the two processes (storing the input && testing the numbers)
    for (ui number=0; number<displays; number++) {
      std::cin >> display;
      container.push_back(display);
    }

    // Testing to guess a correct start point
    for (int guessNum = 9; guessNum>=0; guessNum--) {
      bool broken[8], found = true;
      int beginNum = guessNum;
      resetting(broken, 8);

      for (std::string display : container) {
        normalizing(beginNum);
        std::string lightNum = lights[beginNum];
        bool passingFlag = true;

        std::cout << "BeginNum : " << beginNum << std::endl;
        std::cout << "comparingNum : " << lightNum << std::endl;
        std::cout << "originalNum  : " << display << std::endl;

        for (ui pos=0; pos<7; pos++) {
          if (lightNum[pos] != display[pos] && display[pos] == '1') {
            std::cout << "First" << std::endl;
            passingFlag = false;
          } else if ((lightNum[pos] != display[pos]) && !broken[pos]) {
            std::cout << "Second" << std::endl;
            broken[pos] = true;
          } else if (display[pos] == '1' && broken[pos]) {
            std::cout << "Third" << std::endl;
            passingFlag = false;
          } else {
            std::cout << "Passing" << std::endl;
          }
        }  
      
        if (passingFlag) {
          beginNum -= 1;
        } else {
          found = false;
          break;
        }
      }

      if (found) {
        normalizing(beginNum);        
        std::string candidate = lights[beginNum];
        for (ui index=0; index<7; index++) {
          if (broken[index] && candidate[index] == '1')
            candidate[index] = '0';
        } 
        answerContainer.push_back(candidate);
      } 
    }

    if (answerContainer.size() != 1) {
      answer = "ERROR!";
    } else {
      answer = answerContainer[0];
    }

    std::cout << "Case #" << c << ": " << answer << std::endl;
  }

  return 0;
}
