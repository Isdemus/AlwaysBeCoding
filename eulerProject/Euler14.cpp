//
//  main.cpp
//  #14: Longest Collatz sequence
//
//  Created by Jungjae Lee on 5/2/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int million = 1000000;
    int start = 1;
    int count = 1;
    int final = 0;
    long long int next, answer;

    for(start; start<million; start++) {
        long long int starting = start;
        count = 1;
        while(starting != 1) {
            if(starting%2==0) {
                next = starting/2;
            }else {
                next = 3*starting + 1;
                if (next<starting) {
                    cerr << "ERROR" << endl;
                    cout << "start: " << start << " Starting: " << starting << " and Next: " << next << endl;
                    exit(-1);
                }
            }
            count ++;
            starting = next;
        }
        if (count > final) {
            final = count;
            answer = start;
        }
        
    }
    
    cout << answer << endl;
    std::cout << "Completed\n";
    return 0;
}

