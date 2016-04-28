//
//  main.cpp
//  #10: Summation of primes
//
//  Created by Jungjae Lee on 5/1/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
//#include "/Users/jungjaelee/Desktop/ProjectEuler/#10/#10: Summation of primes/#10: Summation of primes/isPrime.cpp"
using namespace std;

bool isPrime(int number, int half, const vector<int> primes) {
    for (int i=0; i<primes.size(); i++) {
        if (half>=primes[i] && number%primes[i]==0)
            {   return false;   }
        else if (half < primes[i])
            {   break;    }
    }
    
    return true;
}

int main(int argc, const char * argv[])
{
    long long int sum = 0;
    vector<int> primes;
    
    for(int i=2; i<2000000; i++) {
        if (isPrime(i, sqrt(i), primes)) {
            primes.push_back(i);
        }
        cout << i << "  " << primes.size() << endl;
    }
    cout << "done" << endl;
    
    for(int i=0; i<primes.size(); i++) {
        sum += primes[i];
    }
    
    cout << sum << endl;
    
    return 0;
}

