//
//  main.cpp
//  #1: Multiples of 3 and 5
//
//  Multiples of 3 and 5
//  Problem 1
//  If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//  Find the sum of all the multiples of 3 or 5 below 1000.
//
//  Created by Jungjae Lee on 4/30/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int sum = 0;
    
    for (int number = 1; number<1000; number++) {
        if (number%3==0 || number%5==0) {
            sum += number;
        }
    }

    cout << sum << endl;
    return 0;
}

