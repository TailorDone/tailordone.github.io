//
//  main.cpp
//  NumberConverter
//
//  Created by Taylor Dunn & Tyler Jette on 9/8/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//


#include "ConversionFunctions.hpp"

void runTests(){
    assert(intToString(-854,16) == "-356");
    assert(stringToInt("-356",16) == -854);
    assert(intToString(-854, 2) == "-1101010110");
    assert(stringToInt("-1101010110", 2) == -854);
    assert(intToString(61453, 16) == "F00D");
    assert(stringToInt("F00D", 16) == 61453);
    assert(intToString(235894, 29) == "9JE8");
}

int main(int argc, const char * argv[]) {
    runTests();
    int infiniteLoop=1;//This is for repeated testing purposes
    while(infiniteLoop==1){
        std::string number1;
        int number2;
        int base1, base2;
        std::cout << "Enter a number, followed by the base of that number " << std::endl;
        std::cin >> number1 >> base1;
        int value1 = stringToInt(number1, base1);
        std::cout << "The value of your number as a decimal integer is " << value1 << std::endl;
        std::cout << "Enter a decimal integer and the base in which you'd like to convert to " << std::endl;
        std::cin >> number2 >> base2;
        std::string value2 = intToString(number2, base2);
        std::cout << "The value of " << number2 << " converted to base " << base2 << " would become " << value2 << std::endl;
    }
    return 0;
}
