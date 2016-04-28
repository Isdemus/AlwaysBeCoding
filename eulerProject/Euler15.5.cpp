
//
//  main.cpp
//  #15: Lattice paths
//
//  Created by Jungjae Lee on 5/2/13.
//  Copyright (c) 2013 Jungjae Lee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Coord {
public:
    Coord();
    Coord(int X, int Y);
    virtual ~Coord();
    
//    bool isFinished();
//    bool isRight();
//    bool isBottom();
    
    //Getters
    int getX();
    int getY();
    long long int getValue();
    Coord* getLeft();
    Coord* getUp();
    Coord* getDown();
    Coord* getRight();
    
    //Setters
    void setLeft(Coord* Left) {
        left = Left;
    }
    void setUp(Coord* Up) {
        up = Up;
    }
    void setDown(Coord* Down) {
        down = Down;
    }
    void setRight(Coord* Right) {
        right = Right;
    }
    void setValue() {
        if(left == NULL && up == NULL) {
            value = 1;
        }else if(left == NULL) {
            value = up->getValue();
        }else if (up == NULL) {
            value = left->getValue();
        }else {
            value = left->getValue() + up->getValue();
        }
    }
    
private:
    long long int value;
    int x;
    int y;
    Coord* left;
    Coord* up;
    Coord* right;
    Coord* down;
};

/*
int mapping(long long int& count, Coord* direction) {
    if(direction->isFinished()) {
        return count+1;
    }else if(direction->isRight()) {
        return count+1;
    }else if(direction->isBottom()) {
        return count+1;
    }else {
        int x = direction->getX();
        int y = direction->getY();
        
        Coord* direction2 = new Coord(x+1, y);
        Coord* direction3 = new Coord(x, y+1);
        long long int count2 = 0;
        long long int count3 = 0;
        
        count = count + mapping(count2, direction2) + mapping(count3, direction3);
        
        delete direction2;
        delete direction3;
        
        cout << "X: " << direction->getX() << "  Y: " << direction->getY() << "  count: " << count << endl;


        return count;
    }
}
*/

int main(int argc, const char * argv[])
{
    int SIZE = 21;
    vector<Coord*> bottom;
    Coord* start;
    Coord* up = NULL;

    //creating the nodes and link "up" && "down" only
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            Coord* direction = new Coord(i,j);
            if(i==0 && j==0) {
                start = direction;
                up = direction;
            }else if(j==0) {
                up = direction;
            }else if(up != NULL) {
                direction->setUp(up);
                up->setDown(direction);
                if(j==SIZE-1) {
                    up = NULL;
                    bottom.push_back(direction);
                }else {
                    up = direction;
                }
            }
        }
    }

    if(bottom.size() != SIZE) {
        cerr << "ERROR" << endl;
        cerr << "SIZE: " << SIZE << " and the actual size: " << bottom.size() << endl;
        exit(-1);
    }
    
    for(int i=0; i<SIZE; i++) {
        Coord* direction = bottom[i];
        Coord* next = NULL;
        bool notice = false;
        if(i != SIZE-1) {
            next = bottom[i+1];
            notice = true;
        }
        
        while(notice) {
            direction->setRight(next);
            next->setLeft(direction);
        
            if(direction->getUp() != NULL && next->getUp() != NULL) {
                direction = direction->getUp();
                next = next->getUp();
            }else {
                notice = false;
            }
        }
    }
    cout << "Linking Completed" << endl;
    cout << "Last one's left: " << bottom[20]->getLeft()->getX() << " " << bottom[20]->getLeft()->getY() << " and up:" << bottom[20]->getUp()->getX() << " " << bottom[20]->getUp()->getY() << endl;
        
    Coord* direction = start;
    //cout << "x: " << start->getX() << " y: " << start->getY() << endl;
    //setting values
    for(int i=0; i<SIZE; i++) {
        if (i != 0) {
            direction = direction->getDown();
        }
        Coord* current = direction;
        while(current->getRight() != NULL) {
            current->setValue();
            current = current->getRight();
        }
        current->setValue();
    }
    
    cout << "The count is: " << bottom[bottom.size()-1]->getValue() << endl;
    std::cout << "Completed\n";
    return 0;
}

//constructor
Coord::Coord() : x(0), y(0), value(1), left(NULL), up(NULL), right(NULL), down(NULL) {}
Coord::Coord(int X, int Y) : x(X), y(Y), value(1), left(NULL), up(NULL), right(NULL), down(NULL) {}

//destructor
Coord::~Coord() {}

/*
bool Coord::isFinished() {
    if(x==20 && y==x) {
        return true;
    }else {
        return false;
    }
}


bool Coord::isRight() {
    if(x==20) {
        return true;
    }else {
        return false;
    }
}

bool Coord::isBottom() {
    if(y==20) {
        return true;
    }else {
        return false;
    }
    
}
*/

int Coord::getX() {
    return x;
}

int Coord::getY() {
    return y;
}

long long int Coord::getValue() {
    return value;
}

Coord* Coord::getLeft() {
    return left;
}

Coord* Coord::getUp() {
    return up;
}

Coord* Coord::getRight() {
    return right;
}

Coord* Coord::getDown() {
    return down;
}