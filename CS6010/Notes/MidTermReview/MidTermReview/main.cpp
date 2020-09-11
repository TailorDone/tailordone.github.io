//
//  main.cpp
//  MidTermReview
//
//  Created by Taylor Dunn on 9/11/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

void f(const std::string& s){
    //s+=....
    //this would be a compiler erro
}
void swap(int& x, int& y);
//x is a new name for an existing int variable

int main(int argc, const char * argv[]) {
    //const When you put const in front of a type, it means you can never change that thing
    const int i = 10;
    //i++; This will give a compiler error
    //We see this for function parameters
    //for (const student& s : class) Good for : each loops
    return 0;
}
