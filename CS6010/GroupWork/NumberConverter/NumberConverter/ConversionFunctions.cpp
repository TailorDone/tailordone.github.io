//
//  ConversionFunctions.cpp
//  NumberConverter
//
//  Created by Taylor Dunn & Tyler Jette on 9/9/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "ConversionFunctions.hpp"

int stringToInt(std::string numberAsString, int base) {
    int numericValue; //The value of the char when changed to an int
    int total = 0; //The total of all current characters converted to ints thus far
    int sign = 1; //Will be used to determine the sign of the final integer
    int startIndex = 0; //Where the loop to convert characters to ints should start
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
        //TODO make this be able to handle the values between 'a' and 'z'
        if(c >= 'a' && c <= 'z'){
            numericValue = c - 'a'+ 10;
        } else {
            numericValue = c - '0';
        }
        total+= pow(base,numberAsString.size()-i-1) * numericValue;
        }
    return total * sign;
}

std::string intToString(int value, int base){
    int remainderInt, sign = 1;
    std::string remainderString, stringValue, reverse;
    //If the value is negative, store sign as -1
    if(value < 0){
        sign = -1;
        value*=-1;//Changes the number to a positive
    }
    while(value > 0){
        remainderInt = value % base;
        remainderString = std::to_string(remainderInt);//Converts the remainder from integer to string
        //if the remiander is greater than 10 it will convert to a letter. Assumption is that value will not exceed 35 (10 numbers + 26 letters)
        if(remainderInt >= 10){
            remainderString = remainderInt + 'A' - 10;
        }
        stringValue+=remainderString;
        value = value/base;
    }
    //Reverse the order of the string
    for (char value : stringValue){
            reverse = value + reverse;
    }
    //Converts number back to a negative if it started as a negative
    if (sign==-1){
        reverse = "-" + reverse;
    }
    return reverse;
}
