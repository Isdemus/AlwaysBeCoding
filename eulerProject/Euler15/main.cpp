
//
//  main.cpp
//  #15: Lattice paths
//
//  Created by Jungjae Lee on 5/2/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Coord.h"
using namespace std;

int mapping(int& count, Coord* direction) {
    if(direction->isFinisheD()) {
        return count;
    }else if(direction->isRight()) {
        return count+1;
    }else if(direction->isBottom()) {
        return count+1;
    }else {
        int x = direction->x;
        int y = direction->y;
        
        Coord* direction2 = new Coord(x+1, y);
        Coord* direction3 = new Coord(x, y+1);

        count = count + mapping(count, direction2) + mapping(count, direction3);
        
        delete direction2;
        delete direction3;
        
        return count;
    }
}

int main(int argc, const char * argv[])
{
    int count = 0;    
    Coord* direction = new Coord();
    
    mapping(count, direction);
    
    delete direction;
    
    cout << "The count is: " << count << endl;
    std::cout << "Completed\n";
    return 0;
}

