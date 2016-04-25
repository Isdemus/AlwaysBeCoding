//
//  main.cpp
//  #3: Largest prime factor
//
//  Created by Jungjae Lee on 4/30/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include "math.h"

bool isPrime(int number) {
    int sqt = sqrt(number);
    for(int i=2; i<=sqt; i++) {
        if (number%i==0) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[])
{
    long int number = 600851475143;
    int number2 = 1;
    int final = 0;
    
    for(number2; number2<=sqrt(number); number2++) {
        if(number%number2==0 && isPrime(number2)) {
            final = number2;
        }
    }

    std::cout << final << std::endl;
    return 0;
}

