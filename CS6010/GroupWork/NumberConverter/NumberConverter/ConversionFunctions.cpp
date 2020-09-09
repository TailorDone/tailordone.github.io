//
//  ConversionFunctions.cpp
//  NumberConverter
//
//  Created by Taylor Dunn & Tyler Jette on 9/9/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "ConversionFunctions.hpp"

int stringToInt(std::string numberAsString, int base) {
    int numericValue, total = 0, sign = 1, startIndex = 0;
    char c;
    //If there is a negative, the index will start at 1 instead of 0
    if (numberAsString[0] == '-') {
        sign = -1;
        startIndex = 1;
    }
    for(int i = startIndex; i < numberAsString.size(); i++){
        //Changes the value to lowercase (only matters for A,B,C,D,E,F)
        c = tolower(numberAsString[i]);
        //Changes value from character to integer
        if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f'){
            numericValue = c - 'a'+ 10;
        } else {
            numericValue = c - '0';
        }
        total+= pow(base,numberAsString.size()-i-1) * numericValue;
        }
    return total * sign;
}
