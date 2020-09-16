//
//  Tests.cpp
//  DIYVector
//
//  Created by Taylor Dunn on 9/15/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "Tests.hpp"
#include "Vector.hpp"

void runTests(){
    MyVector testVector = makeVector(10);
    assert(testVector.size==0); //Test that size starts at 0
    popBack(testVector);
    assert(testVector.size==0); //Check that if the size is 0 that size doesn't go into the negatives
    for (int i = 0; i < 10; i ++){
        testVector.beginning[i]=i;
        testVector.size++;
    }
    assert(testVector.capacity==10); //Test that capacity is 10 after 10 values have been filled
    assert(testVector.size == 10); //Test that size is 10 after 10 values have been filled
    assert(get(testVector,3) == 3); //Test that the value at index 3 is 3
    set(testVector, 5, 12345);
    assert(get(testVector,5)==12345); //Test that the value at 5 is now 12345
    pushBack(testVector,10);
    assert(testVector.capacity ==20); //Test that adding an element when at capacity will double capacity
    assert(testVector.size ==11); //Test that the size increases when the capacity changes
    popBack(testVector);
    assert(testVector.capacity ==20); //Test that popback does not change the capacity back down
    assert(testVector.size ==10); //Test that popback decreases the size by one
    growVector(testVector);
    assert(testVector.capacity==40); //Tests that grow vector changes the capacity
    assert(testVector.size == 10); //But that grow vector does not change the size
    freeVector(testVector);
    assert(testVector.beginning == nullptr); //Test that free vector has a nullpointer
    //assert(index >= 0 && index < size); Want to test that you can't get an index that doesn't exist and you can't set an index that doesn't exist. Currently throws errors in the code.
}
