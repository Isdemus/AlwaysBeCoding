//
//  main.cpp
//  #18: Maximum path sum I
//
//  Created by Jungjae Lee on 5/9/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct energy {
    int power;
    int sum;
};

int main(int argc, const char * argv[])
{
    //starting ahead
    vector<int*> triangle; //starting from top to bottom
    int level;
    
    cout << "Please insert the level of the triangle" << endl;
    cin >> level;
    
    //filling the triangle with floors
    for(int i=0; i<level; i++) {
        int* array = new int[i+1];
        triangle.push_back(array);
    }
    
    //filling each floor
    for(int i=0; i<level; i++) {
        int* array = triangle[i];
        for(int j=0; j<i+1; j++) {
            int input;
            cin >> input;
            array[j] = input;
        }
    }
    
    int sum = 0;
    start(
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

