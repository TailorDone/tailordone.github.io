//
//  Vector.hpp
//  DIYVector
//
//  Created by Taylor Dunn on 9/15/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <iostream>
#include "Tests.hpp"

//In this lab we'll modify the Vector struct/functions you wrote yesterday to make it more like std::vector. Re-organize your code by doing the following:
//
//change your vector struct into a vector class (this literally just requires replacing struct with class
//make all your data members private
//convert makeVector into a constructor
//convert get, set, push_back, pop_back, growVector, and freeVector into methods
//add methods getSize() and getCapacity() to return the size and capacity of the vector (since your member variables are now private, you need these methods for users to be able to see those values)
//Modify your testing code to work with your reorganized vector code

class MyVector{
    int* beginning;
    int capacity;
    int size;
public:
    MyVector(int intialCapacity); //Constructor
    MyVector(int initialCapacity, int desiredSize); //Constructor that fills in values up to desired size
    void freeVector();
    int getSize();
    int getCapacity();
    int get(int index);
    void set(int index, int newValue);
    void pushBack(int value);
    void popBack();
    void growVector();
};


#endif /* Vector_hpp */
