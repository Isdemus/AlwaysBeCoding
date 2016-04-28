//
//  Coord.h
//  #15: Lattice paths
//
//  Created by Jungjae Lee on 5/4/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#ifndef ___15__Lattice_paths__Coord__
#define ___15__Lattice_paths__Coord__

#include <iostream>
#include "Coord.cpp"

class Coord {
public:
    Coord();
    Coord(int X, int Y);
    virtual ~Coord();
    
    bool isFinished();
    bool isRight();
    bool isBottom();
    
private:
    int x;
    int y;
};


#endif /* defined(___15__Lattice_paths__Coord__) */
