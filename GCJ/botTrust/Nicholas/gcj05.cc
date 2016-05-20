/*
Google Code Jam Entrance Test
(Bot Trust: https://code.google.com/codejam/contest/975485/dashboard)

Used Algorithm Method: 
Coded by isdemus (May 20 2016)
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main (int argc, char* argv[]) {
	unsigned int cases, buttons, move; 
	char task;

	cin >> cases;

	for (int c=1; c<=cases; c++) {
		unsigned int minimumTime = 0;
		unsigned int orangePosition = 1;
		unsigned int bluePosition = orangePosition;

		vector<unsigned int> orangeSequence;
		vector<unsigned int> blueSequence;
		vector<char> taskSequence;

		cin >> buttons;		

		// Storing the input into our vectors
		for (unsigned int element=0; element<buttons; element++) {
			cin >> task;
			cin >> move;

			taskSequence.push_back(task);
				
			if (task == 'O')
				orangeSequence.push_back(move);
			else
				blueSequence.push_back(move);

			cout << "given element: " << task << " " << move << endl;
		} 

		while(taskSequence.size()) {
			char currentTask = taskSequence.front();
			
			int blueFront = 0;
			int orangeFront = 0;
			int minOrangeReq = 0;
			int minBlueReq = 0;

			if (!orangeSequence.empty()) {
				orangeFront = orangeSequence.front();
				int tempFront = orangeFront - orangePosition;
				minOrangeReq = abs(tempFront);
			}
			if (!blueSequence.empty()) {
				blueFront = blueSequence.front();
				int tempFront = blueFront - bluePosition;
				minBlueReq = abs(tempFront);
			}
			
			if (currentTask == 'O' && minOrangeReq >= minBlueReq) {
				minimumTime += minOrangeReq + 1;
				orangePosition = orangeFront;
				bluePosition = blueFront;
				taskSequence.erase(taskSequence.begin());
				if (!orangeSequence.empty())
					orangeSequence.erase(orangeSequence.begin());
			}else if (currentTask == 'O') {
				minimumTime += minOrangeReq + 1;
				orangePosition = orangeFront;
				bluePosition > blueFront ? 
					bluePosition -= minOrangeReq + 1 : bluePosition += minOrangeReq + 1; 
				taskSequence.erase(taskSequence.begin());
				if (!orangeSequence.empty())
					orangeSequence.erase(orangeSequence.begin());	
			}else if (currentTask == 'B' && minBlueReq >= minOrangeReq) {
				minimumTime += minBlueReq + 1;
				orangePosition = orangeFront;
				bluePosition = blueFront;
				taskSequence.erase(taskSequence.begin());
				if (!blueSequence.empty())
					blueSequence.erase(blueSequence.begin());
			}else {
				minimumTime += minBlueReq + 1;
                                orangePosition > orangeFront ?
					orangePosition -= minBlueReq + 1 : orangePosition += minBlueReq + 1; 
                                bluePosition = blueFront;
                                taskSequence.erase(taskSequence.begin());
                                if (!blueSequence.empty())
					blueSequence.erase(blueSequence.begin());
			}
		}

		cout << "Case #" << c << ": " << minimumTime << endl;
	}

	return 0;
}

