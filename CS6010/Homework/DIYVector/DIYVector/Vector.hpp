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
#include <string>
#include <compare>
#include "Tests.hpp"

template <typename T>
class MyVector{
    T* beginning;
    int capacity;
    int size;
public:
    MyVector<T>(const MyVector<T>& vector);//Copy Constructor
    MyVector<T>& operator=(const MyVector<T>& vector); //Make a copy when the vector already exists
    ~MyVector<T>();//Deconstructor
    
    MyVector<T>(int intialCapacity); //Constructor
    MyVector<T>(int initialCapacity, int desiredSize); //Constructor that fills in values up to desired size
    void freeVector();
    int getSize();
    int getCapacity();
    T get(int index);
    void set(int index, T newValue);
    void pushBack(T value);
    void popBack();
    void growVector();
    T operator[](int index) const;
    T& operator[](int index);
    bool operator==(const MyVector<T>& rhs);
    bool operator<(const MyVector<T>& rhs);
};

template <typename T>
bool MyVector<T>::operator==(const MyVector<T>& rhs){
    if (size != rhs.size || capacity != rhs.capacity){
        return false;
    }
    for(int i = 0; i < size; i++){
        if (beginning[i] != rhs.beginning[i]){
            return false;
        }
    }
    return true;
}

template <typename T>
bool MyVector<T>::operator<(const MyVector<T>& rhs){
    if (size <= rhs.size){
        for(int i = 0; i < size; i++){
            if (beginning[i] > rhs[i]){
                return false;
            }
        }
    } else {
        for(int i = 0; i < rhs.size; i++){
            if (beginning[i] > rhs[i]){
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool operator!=(MyVector<T>& lhs, MyVector<T>& rhs){
    return(!(lhs==rhs));
}

template <typename T>
bool operator>(MyVector<T>& lhs, MyVector<T>& rhs){
    return (rhs < lhs);
}

template <typename T>
bool operator>=(MyVector<T>& lhs, MyVector<T>& rhs){
    return (rhs < lhs || lhs == rhs);
}

template <typename T>
bool operator<=(MyVector<T>& lhs, MyVector<T>& rhs){
    return (lhs < rhs || lhs == rhs);
}

template <typename T>
MyVector<T>::MyVector(int initialCapacity){
    assert(initialCapacity > 0);
    capacity = initialCapacity;
    size = 0;
    beginning = new T [initialCapacity];
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& vector){
    assert(vector.capacity > 0);
    capacity = vector.capacity;
    size = vector.size;
    beginning = new T [vector.capacity];
    for (int i = 0; i < size; i++){
        beginning[i] = vector[i];
    }
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& vector){
    if (this == &vector){
        return *this;
    }
    delete [] beginning;
    beginning = new T [vector.capacity];
    size = vector.size;
    capacity = vector.capacity;
    for(int i = 0; i < size; i++){
        beginning[i] = vector.beginning[i];
    }
    return *this;
}

template <typename T>
MyVector<T>::~MyVector<T>(){
    delete [] beginning;
}

template <typename T>
MyVector<T>::MyVector(int initialCapacity, int desiredSize){
    assert(initialCapacity > 0);
    capacity = initialCapacity;
    size = desiredSize;
    beginning = new T [initialCapacity];
    for (int i = 0; i < size; i ++){
        set(i,i);
    }
}

template <typename T>
T MyVector<T>::operator[](int index) const{
    return *(beginning + index);
}

template <typename T>
T& MyVector<T>::operator[](int index){
    return *(beginning + index);
}

template <typename T>
int MyVector<T>::getSize(){
    return size;
}

template <typename T>
int MyVector<T>::getCapacity(){
    return capacity;
}

template <typename T>
void MyVector<T>::freeVector(){
    delete []beginning;
    beginning = nullptr;
}

template <typename T>
void MyVector<T>::pushBack(T value){
    if (size == capacity){
         growVector();
    }
    beginning[size] = value;
    size++;
}

template <typename T>
void MyVector<T>::popBack(){
    if (size>0){
    size--;
    }
}

template <typename T>
T MyVector<T>::get(int index){
    assert(index>=0 && index < size);
    return *(beginning + index);
}

template <typename T>
void MyVector<T>::set(int index, T newValue){
    assert(!(index >=0 && index > size));
    *(beginning + index) = newValue;
}

template <typename T>
void MyVector<T>::growVector(){
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

#endif /* Vector_hpp */
