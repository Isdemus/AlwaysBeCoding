//
//  main.cpp
//  #11: Largest product in a grid
//
//  Created by Jungjae Lee on 5/1/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

bool process(long long int mult, long long int& final) {
    if(mult>final) {
        final = mult;
        return true;
    }
    return false;
}
int main(int argc, const char * argv[])
{
    long long int final = 0;
    long long int mult;
    int given_integer;
    const int SIZE = 20;
    //vector<int> board;
    int board[SIZE][SIZE]; //first one is column -- the other is row

    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            cin >> given_integer;
            board[j][i] = given_integer;
//            cout << "here: " << i << " " << j << " " << given_integer << endl;
        }
    }
    cout << "values are inserted" << endl;
    
    for(int i=0; i<17; i++) {
        for(int j=0; j<SIZE; j++) {
            mult = board[i][j]*board[i+1][j]*board[i+2][j]*board[i+3][j];
            if( process(mult, final) ) {
                cout << "i: " << i << " j: " << j << "mult: " << mult << endl;
                cout << board[i][j] << endl;
                cout << board[i+1][j] << endl;
                cout << board[i+2][j] << endl;
                cout << board[i+3][j] << endl;
            }
        }
    }
    cout << "right/left done\tfinal: " << final << endl;

    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<17; j++) {
            mult = board[i][j]*board[i][j+1]*board[i][j+2]*board[i][j+3];
            if( process(mult, final) ) {
                cout << "i: " << i << " j: " << j << "mult: " << mult << endl;
                cout << board[i][j];
                cout << board[i][j+1];
                cout << board[i][j+2];
                cout << board[i][j+3];
            }
        }
    }
    cout << "up/down done\tfinal: " << final << endl;
    
    for(int i=0; i<17; i++) {
        for(int j=0; j<17; j++) {
            mult = board[i][j]*board[i+1][j+1]*board[i+2][j+2]*board[i+3][j+3];
            if( process(mult, final) ) {
                cout << "i: " << i << " j: " << j << "mult: " << mult << endl;
                cout << board[i][j] << endl;
                cout << board[i+1][j+1] << endl;
                cout << board[i+2][j+2] << endl;
                cout << board[i+3][j+3] << endl;
            }
        }
    }
    cout << "right diagonal done\tfinal: " << final << endl;
    
    for(int i=3; i<SIZE; i++) {
        for(int j=0; j<17; j++) {
            mult = board[i][j]*board[i-1][j+1]*board[i-2][j+2]*board[i-3][j+3];
            if( process(mult, final) ) {
                cout << "i: " << i << " j: " << j << "mult: " << mult << endl;
                cout << board[i][j] << endl;
                cout << board[i-1][j+1] << endl;
                cout << board[i-2][j+2] << endl;
                cout << board[i-3][j+3] << endl;
            }
        }
    }
    cout << "left diagonal done\tfinal: " << final << endl;
    
    cout << final << endl;
//    std::cout << "Hello, World!\n";
    return 0;
}

