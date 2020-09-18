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

//Overload the [] operator (both versions) so you can access elements with the [] syntax like someVector[5] = 3; and cout << someVector[0];

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
    int operator[](int index) const;
    int& operator[](int index);
};


#endif /* Vector_hpp */
