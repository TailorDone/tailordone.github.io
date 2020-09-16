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
    MyVector testVector2 = MyVector(10);
    assert(testVector2.getSize()==0); //Test that size starts at 0
    testVector2.popBack();
    assert(testVector2.getSize()==0); //Check that if the size is 0 that size doesn't go into the negatives
    MyVector testVector = MyVector(10,10);
    assert(testVector.getCapacity()==10); //Test that capacity is 10 after 10 values have been filled
    assert(testVector.getSize() == 10); //Test that size is 10 after 10 values have been filled
    assert(testVector.get(3) == 3); //Test that the value at index 3 is 3
    testVector.set(5, 12345);
    assert(testVector.get(5)==12345);//Test that the value at 5 is now 12345
    testVector.set(9, 999); //Can set the last element in a vector
    assert(testVector.get(9) == 999); //Can get the last element in a vector
    testVector.set(0, 01010); //Can set the fist element in a vector
    assert(testVector.get(0) == 01010); //Can get the first element in a vector
    testVector.pushBack(10);
    assert(testVector.getCapacity()==20); //Test that adding an element when at capacity will double capacity
    assert(testVector.getSize() ==11); //Test that the size increases when the capacity changes
    testVector.popBack();
    assert(testVector.getCapacity() ==20); //Test that popback does not change the capacity back down
    assert(testVector.getSize() ==10); //Test that popback decreases the size by one
    testVector.growVector();
    assert(testVector.getCapacity()==40); //Tests that grow vector changes the capacity
    assert(testVector.getSize() == 10); //But that grow vector does not change the size
    testVector.freeVector();
    //assert(testVector.beginning == nullptr); Unsure how to test freeVector now
}
