//
//  main.cpp
//  Classes
//
//  Created by Taylor Dunn on 9/16/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include "Methods.hpp"

//strcuts will go in header

//structs are "dumb"
//classes are for related data with "invariants"

//methods are functions that beclong to a class or struct and can access privte fields

//(c from main).x

int main(int argc, const char * argv[]) {
    //std::cout<<c.getx(); doesn't say what getx() actually does
    int x = 3;
    
    //vecOfCs[3].getx();
   
    //Constructors function that runs when we create a new object
    //c c(3); // x = 3, y = 3^2
    //Two parts. Declaration.
    MovingAverage m;
    MovingAverage mm{};
    MovingAverage mmm = MovingAverage();
    //MovingAverage m();
    return 0;
}
