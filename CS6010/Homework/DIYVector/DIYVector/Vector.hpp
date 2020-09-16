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

struct MyVector{
    int* beginning;
    int capacity;
    int size;
};

MyVector makeVector(int initialCapacity);

void freeVector(MyVector& vector);

void pushBack(MyVector& myVec, int value);

void popBack(MyVector& myVec);

int get(MyVector& myVec, int index);

void set(MyVector& myVec, int index, int newValue);

void growVector(MyVector& myVec);
#endif /* Vector_hpp */
