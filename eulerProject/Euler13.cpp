//
//  main.cpp
//  #13: Large sum
//
//  Created by Jungjae Lee on 5/2/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "math.h"
#include <vector>
#include <stdlib.h>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[])
{
    vector<int> final;
    vector<int> New;
    string line;
    ifstream myfile ("/Users/jungjaelee/Desktop/ProjectEuler/#13/#13: Large sum/#13: Large sum/input");
    
    for(int i=0; i<52; i++) {
        final.push_back(0);
    }
    
    if(myfile.is_open()) {
        cout << "opened" << endl;

        while(getline(myfile, line)) {
//            cout << "line: " << line << endl;
//            cout << line.length() << endl;
        
            for(int i=0; i<line.length(); i++) {
                New.push_back(line[i]);
      //          cout << "before: " << New[i] << endl;
                New[i] -= 48;
       //         cout << "after: " << New[i] << endl;
                final[i+2] += New[i];
//                cout << "i: " << i << " and num: " << line[i] << endl;
            }
            
//            cout << New.size() << endl;
            for (int i=0; i<50; i++) {
                New.pop_back();
            }
        }
    }
    
    for (int i=51; i>=0; i--) {
        if(final[i]>=10) {
            final[i-1] += (final[i]/10);
            final[i] = final[i]%10;
        }
    }
    
    cout << "The Number: ";
    for(int i=0; i<final.size(); i++) {
        cout << final[i];
    }
    cout << endl;
    
    cout << "The wanted answer is ";
    for (int i=0; i<10; i++) {
        cout << final[i];
    }
    cout << endl;
    
    std::cout << "Completed\n";
    return 0;
}

