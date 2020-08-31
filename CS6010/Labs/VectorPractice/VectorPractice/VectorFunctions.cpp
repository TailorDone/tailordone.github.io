//
//  VectorFunctions.cpp
//  VectorPractice
//
//  Created by Taylor Dunn on 8/31/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "VectorFunctions.hpp"
#include <vector>
#include <iostream>
using namespace std;

/**
 Sums all the integers in a vector into a single integer
 @Param v an integer vector
 @Return Returns an integer of the sum
 */
int sum(vector<int> v){
    int sum = 0;
    for (int element : v){
        sum += element;
    }
    return sum;
}

/**
Takes a string and returns a vector of the characters in the string
@Param s a string
@Return Returns a vector of characters in order from the string
*/
vector<char> stringToVec(string s){
    vector<char> vectorOfCharacters;
    for (char c : s){
        vectorOfCharacters.push_back(c);
    }
    return vectorOfCharacters;
}

/**
Takes an integer vector and reverses all the elements
@Param v an integer vector
@Return Returns an integer vector where the elements are reversed
*/
vector<int> reverse(vector<int> v){
    vector<int> reversedVector;
    //Geting the size of the vector since the vector size will change due to pop in the function.
    int fixedSize = v.size();
    for (int i = 0; i < fixedSize; i++){
        reversedVector.push_back(v.back());
        v.pop_back();
    }
    return reversedVector;
}
