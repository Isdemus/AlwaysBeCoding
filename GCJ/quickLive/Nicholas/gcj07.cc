/*
Google Code Jam Entrance Test
(Quick Live: https://code.google.com/codejam/contest/1985486/dashboard)

Used Algorithm Method: c++11 features (auto, lambda)
Coded by isdemus (May 26 2016)
*/

#include <iostream>
#include <vector>

typedef unsigned int ui;
#define fi(cases) for(ui c=1; c<=cases; c++)
#define custout(case, diff) cout << "Case #" << case << ": " << diff << endl;
using namespace std;

int main (int argc, char* argv[]) {
  ui cases;
  cin >> cases;

  fi (cases) {
    ui playerNum, teamA, teamB, teamANum, teamBNum, level, diff;
    teamA = teamB = teamANum = teamBNum = 0;
    vector<ui> queue;
    cin >> playerNum;

    fi (playerNum) {
      cin >> level;

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

    for (int i : queue) {
      cout << i << endl;
    }

    const ui SIZE = queue.size();
    fi (SIZE) {
      ui medianIndex = (queue.size()-1)/2;
      ui median = queue[medianIndex];
      cout << "median: " << median << " medianIndex: " << medianIndex << endl;
      if (queue.size()%2 && teamANum>=teamBNum) { // odd number -> allocating to the team with less teammates
        teamB += median;
        teamBNum += 1;
      } else if (queue.size()%2) {
        teamA += median;
        teamANum += 1;
      } else if (teamA >= teamB) { // even number -> allocating to the team with larger sum
        teamA += median;
        teamANum += 1;
      } else {
        teamB += median;
        teamBNum += 1;
      }
      queue.erase(queue.begin() + medianIndex);
      cout << "teamA: " << teamA << " : teamB: " << teamB << endl;
    }
    
    diff = teamA>=teamB ? teamA-teamB : teamB-teamA;
    custout(c, diff);
  }
   

  return 0;
}
