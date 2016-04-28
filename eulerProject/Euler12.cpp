//
//  main.cpp
//  #12: Highly divisible triangular number
//
//  Created by Jungjae Lee on 5/2/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include "math.h"
using namespace std;

int main(int argc, const char * argv[])
{
    int current = 1;
    int final;
    
    while(true) {
        int number = current * (current + 1) / 2;
        int howMany = 0;

//        cout << "starting: (current): " << current << " and (number): " << number << endl;
        for (int i=1; i<sqrt(number); i++) {
            if (number%i==0) {
                howMany += 1;
            }
        }
//        cout << "howMany: " << howMany << endl;
        
        howMany = howMany * 2;
        
        if (sqrt(number) * sqrt(number) == number) {
            howMany += 1;
        }
        
        if (howMany > 500) {
            final = number;
            break;
        }
        
        current ++;
    }
    
    
    cout << final << endl;
    return 0;
}

