//
//  Vector.cpp
//  DIYVector
//
//  Created by Taylor Dunn on 9/15/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "Vector.hpp"

MyVector makeVector(int initialCapacity){
    assert(initialCapacity > 0);
    MyVector createdVector;
    createdVector.capacity = initialCapacity;
    createdVector.size = 0;
    createdVector.beginning = new int[initialCapacity];
    return createdVector;
}

void freeVector(MyVector& vector){
    delete []vector.beginning;
    vector.beginning = nullptr;
}

void pushBack(MyVector& myVec, int value){
    if (myVec.size == myVec.capacity){
         growVector(myVec);
    }
    myVec.beginning[myVec.size] = value;
    myVec.size++;
}

void popBack(MyVector& myVec){
    if (myVec.size>0){
    myVec.size--;
    }
}

int get(MyVector& myVec, int index){
    assert(index>=0 && index < myVec.size);
    return *(myVec.beginning + index);
}

void set(MyVector& myVec, int index, int newValue){
    assert(!(index >= 0 && index > myVec.size));
    *(myVec.beginning + index) = newValue;
}

void growVector(MyVector& myVec){
    MyVector biggerVec = makeVector(myVec.capacity*2);
    for (int i = 0; i < myVec.size; i++){
        set(biggerVec, i, get(myVec,i));
        biggerVec.size++;
    }
    freeVector(myVec);
    myVec = biggerVec;
    biggerVec.beginning = nullptr;
}
