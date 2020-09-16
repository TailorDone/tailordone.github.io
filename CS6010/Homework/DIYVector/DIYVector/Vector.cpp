//
//  Vector.cpp
//  DIYVector
//
//  Created by Taylor Dunn on 9/15/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "Vector.hpp"

MyVector::MyVector(int initialCapacity){
    assert(initialCapacity > 0);
    capacity = initialCapacity;
    size = 0;
    beginning = new int[initialCapacity];
}

MyVector::MyVector(int initialCapacity, int desiredSize){
    assert(initialCapacity >0);
    capacity = initialCapacity;
    size = desiredSize;
    beginning = new int[initialCapacity];
    for (int i = 0; i < size; i ++){
        set(i,i);
    }
}

int MyVector::getSize(){
    return size;
}

int MyVector::getCapacity(){
    return capacity;
}

void MyVector::freeVector(){
    delete []beginning;
    beginning = nullptr;
}

void MyVector::pushBack(int value){
    if (size == capacity){
         growVector();
    }
    beginning[size] = value;
    size++;
}

void MyVector::popBack(){
    if (size>0){
    size--;
    }
}

int MyVector::get(int index){
    assert(index>=0 && index < size);
    return *(beginning + index);
}

void MyVector::set(int index, int newValue){
    assert(!(index >=0 && index > size));
    *(beginning + index) = newValue;
}

void MyVector::growVector(){
    MyVector biggerVec(capacity*2);
    for (int i = 0; i < size; i++){
        biggerVec.set(i, get(i));
        biggerVec.size++;
    }
    freeVector();
    size = biggerVec.size;
    capacity = biggerVec.capacity;
    beginning = biggerVec.beginning;
    biggerVec.beginning = nullptr;
}
