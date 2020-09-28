//
//  ConversionFunctions.hpp
//  NumberConverter
//
//  Created by Taylor Dunn & Tyler Jette on 9/9/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef ConversionFunctions_hpp
#define ConversionFunctions_hpp

#include <stdio.h>
#include <math.h>
#include <vector>
#include <ctype.h>
#include <string>
#include <iostream>

//Takes a string and a desired base and turns it into an int
//Assumption: The base will not exceed 16
int stringToInt(std::string numberAsString, int base);

//Takes an int and a given base and turns it into a String
//Assumption the base will not exceed 36
std::string intToString(int value, int base);

#endif /* ConversionFunctions_hpp */
