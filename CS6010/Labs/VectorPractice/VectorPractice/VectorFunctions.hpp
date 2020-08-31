//
//  VectorFunctions.hpp
//  VectorPractice
//
//  Created by Taylor Dunn on 8/31/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef VectorFunctions_hpp
#define VectorFunctions_hpp

#include <stdio.h>
#include <vector>
using namespace std;
/**
 Sums all the integers in a vector into a single integer
 @Param v an integer vector
 @Return Returns an integer of the sum
 */
int sum(vector<int> v);

/**
Takes a string and returns a vector of the characters in the string
@Param s a string
@Return Returns a vector of characters in order from the string
*/
vector<char> stringToVec(string s);

/**
Takes an integer vector and reverses all the elements
@Param v an integer vector
@Return Returns an integer vector where the elements are reversed
*/
vector<int> reverse(vector<int> v);

#endif /* VectorFunctions_hpp */
