//
//  Coord.cpp
//  #15: Lattice paths
//
//  Created by Jungjae Lee on 5/4/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
using namespace std;

//constructor
Coord::Coord() : x(0), y(0) {}
Coord::Coord(int X, int Y) : x(X), y(Y) {}

//destructor
Coord::~Coord() {}

bool Coord::isFinished() {
    if(x==2 && y==2) {
        return true;
    }else {
        return false;
    }
}

bool Coord::isRight() {
    if(x==2) {
        return true;
    }else {
        return false;
    }
}

bool Coord::isBottom() {
    if(y==2) {
        return true;
    }else {
        return false;
    }
    
}
