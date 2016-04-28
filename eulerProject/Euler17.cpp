//
//  main.cpp
//  #17: Number letter counts
//
//  Created by Jungjae Lee on 5/6/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
using namespace std;

//input: Int (<=100)
int helper(int i) {
    if(i==90 || i==80) {
        return 6;
    }else if(i>80) {
        return 6 + helper(i%10);
    }else if(i>70) {
        return 7 + helper(i%10);
    }else if(i==70) {
        return 7;
    }else if(i==60 || i==50 || i==40) {
        return 5;
    }else if(i>40) {
        return 5 + helper(i%10);
    }else if(i==30 || i==20) {
        return 6;
    }else if(i>20) {
        return 6 + helper(i%10);
    }else if(i==19 || i==18 || i==13 || i==14) {
        return 8;
    }else if(i==17) {
        return 9;
    }else if(i==15 || i==16) {
        return 7;
    }else if(i==11 || i==12) {
        return 6;
    }else if(i==3 || i==7 || i==8) {
        return 5;
    }else if(i==4 || i==5 || i==9) {
        return 4;
    }else if(i==1 || i==2 || i==6 || i==10) {
        return 3;
    }else {
        cerr << "ERROR:helper" << endl;
        cerr << "Number: " << i << endl;
        exit(-1);
    }
}

//Input: Int (<=1000)
int numberToLetter(int number) {
    if (number == 1000) {
        return 11;
    }else if (number >= 100) {
        int basic = helper(number/100) + 7;
        if (number%100 != 0) {
            basic = basic + 3 + numberToLetter(number%100);
        }
        
        return basic;
    }else {
        return helper(number);
    }
}

int main(int argc, const char * argv[])
{
    int count = 1000;
    int sum = 0;
    
    for(int i=1; i<count+1; i++) {
        sum += numberToLetter(i);
    }

    cout << sum << endl;
//    cout << numberToLetter(115) << endl;
    
    std::cout << "Completed\n";
    return 0;
}

