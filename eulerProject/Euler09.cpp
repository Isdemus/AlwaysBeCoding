//
//  main.cpp
//  #9: Special Pythagorean triplet
//
//  Created by Jungjae Lee on 5/1/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include <vector>
//#include <math.h>
#include <stdlib.h>

using namespace std;

struct set {
    int A;
    int B;
    int C;
};

void making_set(int sum, int A, vector<set> &list) {
    int rest = sum - A;
    int maxB = rest/2;
    
    for(int b=A+1; b<=maxB; b++) {
        int c = rest - b;
        if (A>=b || b>=c) {
        }else if (A*A + b*b == c*c) {
            set chart;
            chart.A = A;
            chart.B = b;
            chart.C = c;
            
            list.push_back(chart);
        }
    }
}

int finding_mult(vector<set> list) {
    return list[0].A * list[0].B * list[0].C;
}

int main(int argc, const char * argv[])
{
    int final=0;
    int sum = 1000;
    int maxA = 332;
    vector<set> list;
    
    for(int a=0; a<=maxA; a++) {
        making_set(sum, a, list);
    }

//    cout << list.size() << endl;
    final = finding_mult(list);
    
    cout << final << endl;
    
    return 0;
}

