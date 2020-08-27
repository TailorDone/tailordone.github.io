//
//  main.cpp
//  RomanNumerals
//
//  Created by Taylor Dunn on 8/26/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::string romanNumeral = "";
    int number;
    std::cout << "Give a number, any number!" << std::endl;
    std::cin >> number;
    if (number <= 0) {
        std::cout << "Invalid Input. Must input a postive integer." << std::endl;
        return 1;
    }
    int startingNumber = number;
    while (number > 0){
        if (number >= 1000) {
            number -= 1000;
            romanNumeral += "M";
        } else if (number >= 900){
            number -= 900;
            romanNumeral += "CM";
        } else if (number >= 500){
            number -= 500;
            romanNumeral += "D";
        } else if (number >= 400){
            number -=400;
            romanNumeral += "CD";
        } else if (number >= 100) {
            number -= 100;
            romanNumeral += "C";
        } else if (number >= 90) {
            number -= 90;
            romanNumeral += "XC";
        } else if (number >= 50) {
            number -= 50;
            romanNumeral += "L";
        } else if (number >= 40) {
            number -= 40;
            romanNumeral += "XL";
        } else if (number >= 10){
            number -= 10;
            romanNumeral += "X";
        } else if (number >= 9) {
            number -= 9;
            romanNumeral += "IX";
        } else if (number >= 5) {
            number -= 5;
            romanNumeral += "V";
        } else if (number >= 4) {
            number -= 4;
            romanNumeral += "IV";
        } else if (number >= 1){
            number -= 1;
            romanNumeral += "I";
        }
    }
    std::cout << "Your number " << startingNumber << " as a roman numeral is : " << romanNumeral << std::endl;
    return 0;
}
