// Lib file: abcHelpers.h
// Coded by isdemus (updated on 2016 05 01)
// It is a library file that includes helper functions to use in ABC(Always Be Coding) codes.

// List of helper functions:
// 1. Produce random array
// 2. 
#ifndef _ABCHELPER_H_
#define _ABCHELPER_H_
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

// MS
void print_header(std::string header, int extra);

// Randomly adding elements into an array
void seeding();
int random_size(int size);
int* produce_random_array(int size_of_array);
void print_array(int* array, int size_of_array, std::string header);

// Vector Related
void print_int_vector(std::vector<int> vec);

#endif // ABCHELPER_H

