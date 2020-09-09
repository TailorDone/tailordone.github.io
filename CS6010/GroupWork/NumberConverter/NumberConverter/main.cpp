//
//  main.cpp
//  NumberConverter
//
//  Created by Taylor Dunn & Tyler Jette on 9/8/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//


#include "ConversionFunctions.hpp"

int main(int argc, const char * argv[]) {
    //Tests
    int value = stringToInt("99",10);
    std::cout << value << std::endl;
    int valueNeg = stringToInt("-99",10);
    std::cout << valueNeg << std::endl;
    int value2 = stringToInt("1100",2);
    std::cout << value2 << std::endl;
    int value2Neg = stringToInt("-1100",2);
    std::cout << value2Neg << std::endl;
    int value3 = stringToInt("FF", 16);
    std::cout << value3 << std::endl;
    int value3Neg = stringToInt("-FF", 16);
    std::cout << value3Neg << std::endl;
    int value4 = stringToInt("278", 16);
    std::cout << value4 << std::endl;
    int value4Neg = stringToInt("-278", 16);
    std::cout << value4Neg << std::endl;
    return 0;
}
