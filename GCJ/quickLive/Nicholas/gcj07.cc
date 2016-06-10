/*
Google Code Jam Entrance Test
(Quick Live: https://code.google.com/codejam/contest/1985486/dashboard)

Used Algorithm Method: c++11 features (auto, lambda), simple sorting optional insersion.
Coded by isdemus (May 26 2016)
*/

#include <iostream>
#include <vector>

typedef unsigned int ui;
#define fi(cases) for (ui c=1; c<=cases; c++)
#define fia(cases, end) for (cases; cases<end; cases++)
#define custout(case, diff) cout << "Case #" << case << ": " << diff << endl;

using namespace std;

int main (int argc, char* argv[]) {
  ui cases;
  cin >> cases;

  fi (cases) {
    ui playerNum, teamA, teamB, teamANum, teamBNum, level, diff, sum;
    teamA = teamB = teamANum = teamBNum = sum = 0;
    vector<ui> queue;
    cin >> playerNum;

    fi (playerNum) {
      cin >> level;
      sum += level;

      if (queue.size() == 0) {
        queue.push_back(level);
      } else {
        auto indexToInsert = [&] () { //-> vector<ui>::iterator {
          for (auto it=queue.begin(); it != queue.end(); it++) {
            if (*it > level)
              return it;
          }
          return queue.end();
        };

        queue.insert(indexToInsert(), level);
      }
    }

    diff = sum;
    ui answer = -1;
    const ui SIZE = queue.size();
    ui a=0;
    fia (a, SIZE-3) {
      ui a1 = a+1;
      fia (a1, SIZE-2) {
        ui a2 = a1+1;
        fia (a2, SIZE-1) {
          ui a3 = a2+1;
          fia (a3, SIZE) {
            ui fourSum = queue[a] + queue[a1] + queue[a2] + queue[a3];
            if (fourSum >= sum/2 && fourSum - sum/2 < diff) {
              diff = fourSum - sum/2;
              answer = fourSum - sum; 
            } else if (sum/2 - fourSum < diff) {
              diff = sum/2 - fourSum;
              answer = sum - fourSum;
            }
          }
        }
      }
    }

    cout << "answer: " << diff << endl;
    
    // This is not distributing the players fairly
    fi (SIZE) {
      ui medianIndex = (queue.size()-1)/2;
      ui median = queue[medianIndex];
      if (queue.size()%2 && teamANum>=teamBNum) {
        // odd number -> allocating to the team with less teammates
        teamB += median;
        teamBNum += 1;
      } else if (queue.size()%2) {
        teamA += median;
        teamANum += 1;
      } else if (teamA >= teamB) { 
        // even number -> allocating to the team with larger sum
        teamA += median;
        teamANum += 1;
      } else {
        teamB += median;
        teamBNum += 1;
      }
      queue.erase(queue.begin() + medianIndex);
    }
    
    diff = teamA>=teamB ? teamA-teamB : teamB-teamA;
    custout(c, diff);
  }
   

  return 0;
}
