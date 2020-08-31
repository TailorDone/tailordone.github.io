//
//  main.cpp
//  VectorPractice
//
//  Created by Taylor Dunn on 8/31/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>
#include "VectorFunctions.hpp"

using namespace std;

void runtests(){
    //Setting up scenarios to test
    vector<int> testVector1 = {1, 2, 3};
    vector<int> reversed1 = {3, 2, 1};
    vector<int> testVector2 = {-31, 31, 0};
    vector<int> reversed2 = {0, 31, -31};
    vector<int> testVector3 = {-4, -11, -28};
    vector<int> reversed3 = {-28, -11, -4};
    string testString1 = "Hello";
    vector<char> charVector1 = {'H','e','l','l','o'};
    string testString2 = "a space";
    vector<char> charVector2 = {'a',' ','s','p','a','c','e'};
    string testString3 = "kayak";
    vector<char> charVector3 = {'k','a','y','a','k'};
    //Testing the sum function
    assert(sum(testVector1)==6);
    assert(sum(testVector2)==0);
    assert(sum(testVector3)==-43);
    //Testing the string to vector function
    assert(stringToVec(testString1)==charVector1);
    assert(stringToVec(testString2)==charVector2);
    assert(stringToVec(testString3)==charVector3);
    //Testing the reverse function
    assert(reverse(testVector1)==reversed1);
    assert(reverse(testVector2)==reversed2);
    assert(reverse(testVector3)==reversed3);
}

int main(int argc, const char * argv[]) {
    runtests();
    return 0;
}

