//
//  main.cpp
//  #7: 10001st Prime
//
//  Created by Jungjae Lee on 4/30/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include "math.h"

bool isPrime(int number, int half) {
    for (int i=2; i<number; i++) {
        if (number%i == 0)
            return false;
    }
    
    return true;
}

int main(int argc, const char * argv[])
{
    int count = 0;
    int number = 1;
    
    while(count != 10001) {
        number += 1;
        if (isPrime(number, sqrt(number))) {
            count += 1;
        }
    }
    
    std::cout << number << std::endl;
    
    return 0;
}

