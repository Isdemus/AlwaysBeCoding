//
//  main.cpp
//  #16: Power digit sum
//
//  Created by Jungjae Lee on 5/5/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int exponent = 1000;
    int number = 0;
    int relative_count = exponent - 1;
    int multiplier = 2;
    const int SIZE = 302;
    int final[SIZE];
    
    //setting up every digit is 0
    for(int i=0; i<SIZE; i++) {
        if(i == SIZE-1) {
            final[i] = 2;
        }else {
            final[i] = 0;
        }
    }
    
    //multiplying the last element by the multiplier
    for(int i=0; i<relative_count; i++) {
        for(int i=0; i<SIZE; i++) {
            final[i] *= multiplier;
        }
        for(int j=SIZE-1; j>=0; j--) {
            if(final[j] > 9) {
                final[j-1] += final[j]/10;
                final[j] = final[j]%10;
            }
        }
    }
    
    //outputing
    for(int i=0; i<SIZE; i++) {
        number += final[i];
        cout << final[i];
    }
    cout << endl;
    
    cout << number << endl;
    std::cout << "Completed\n";
    return 0;
}

