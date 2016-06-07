#include <iostream>
#include <cstdlib>

#define stdoutput(a, b) std::printf("Case #%d: %f\n", a, b); 
using namespace std;

typedef unsigned int ui;

void trimming (const double& prevHeight, double& currentHeight, const double& nextHeight) {
  double newHeight = (prevHeight + nextHeight) / 2;
  if (currentHeight > newHeight)
    currentHeight = newHeight;
}

int main (int argc, char* argv[]) {
  int cases;
  cin >> cases;
  for (int c=1; c<=cases; c++) {
    ui numHedges;
    double prevHeight, currentHeight, nextHeight;
    cin >> numHedges;
    cin >> prevHeight;
    cin >> currentHeight;
    cin >> nextHeight;

    for (int h=0; h<numHedges-3; h++) {
      trimming (prevHeight, currentHeight, nextHeight);
      prevHeight = currentHeight;
      currentHeight = nextHeight;
      cin >> nextHeight;
    }

    trimming (prevHeight, currentHeight, nextHeight);

    stdoutput(c, currentHeight);    
  }

  return 0;
}


