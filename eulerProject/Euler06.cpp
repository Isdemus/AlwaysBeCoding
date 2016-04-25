//
//  main.cpp
//  #6: Sum square difference
//
//  Created by Jungjae Lee on 4/30/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include "math.h"

int sumof(int loop) {
    int sum = 0;
    for (int i=1; i<=loop; i++) {
        sum += i*i;
    }
    
    return sum;
}

int squareof(int loop) {
    int sum = 0;
    for (int i=1; i<=loop; i++) {
        sum += i;
    }
    
    return sum*sum;
}

int main(int argc, const char * argv[])
{
    int SoS = sumof(100);
    int SoS2 = squareof(100);
    
    int result = SoS-SoS2;
    result = abs(result);
    
    std::cout << result << std::endl;
    
    return 0;
}

