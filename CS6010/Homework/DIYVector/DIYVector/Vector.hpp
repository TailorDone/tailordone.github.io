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

class MyVector{
    int* beginning;
    int capacity;
    int size;
public:
    MyVector(const MyVector& vector);//Copy Constructor
    MyVector& operator=(const MyVector& vector); //Make a copy when the vector already exists
    ~MyVector();//Deconstructor
    
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
