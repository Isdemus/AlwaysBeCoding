//
//  main.cpp
//  #5: Smallest multiple
//
//  Created by Jungjae Lee on 4/30/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int final = 0;
    int number = 1;
    bool success = false;
    
    while (!success) {
        for(int div=1; div<=20; div++) {
            if(number%div != 0) {
                break;
            }else if (div == 20 && number%div == 0) {
                success = true;
                final = number;
            }
        }
        
        number ++;
    }

    cout << final << endl;
    return 0;
}

