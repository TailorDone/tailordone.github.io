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

