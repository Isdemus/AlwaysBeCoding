//
//  main.cpp
//  #4: Largest palindrome product
//
//  Created by Jungjae Lee on 4/30/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
using namespace std;

bool isPalindrome(int result) {
    //cout << result << endl;
    if(result > 100000) { //123456
        if(result/100000 == result%10) {
            result = (result%100000)/10; //2345
            if(result/1000 == result%10) {
                result = (result%1000)/10;
                if(result/10 == result%10) {
                    return true;
                }
            }
        }
    }else if (result > 10000) {
        return false;
    }
}

int main(int argc, const char * argv[])
{
    int number = 999;
    int result;
    int final=0;
    
    for(number; number>=100; number--) {       
        for(int number2=999; number2>=100; number2--) {
            result = number*number2;
            if(result > final && isPalindrome(result)) {
                cout << "ever2" << endl;
                final = result;
            }
        }
    }
    
    cout << final << endl;
    return 0;
}

