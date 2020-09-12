//
//  assembler.cpp
//  Assembler
//
//  Created by Taylor Dunn on 9/11/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "assembler.hpp"

//Your task is to write a program that takes as input an assembly file, and outputs a file containing the binary machine code representation of the assembly. That's it - you technically don't even need to use the simulator. The simulator will help you debug your assembler.

int stringToInt(std::string numberAsString) {
int numericValue; //The value of the char when changed to an int
int total = 0; //The total of all current characters converted to ints thus far
int sign = 1; //Will be used to determine the sign of the final integer
int startIndex = 0; //Where the loop to convert characters to ints should start
char c;
if (numberAsString[0] == '-') {
    sign = -1;
    startIndex = 1;
}
for(int i = startIndex; i < numberAsString.size(); i++){
    c = numberAsString[i];
    numericValue = c - '0';
    total+= pow(2,numberAsString.size()-i-1) * numericValue;
    }
return total*sign;
}

int8_t regToBit(std::string& reg){
    if (reg == "$0"){
        return 0;
    } else if (reg =="$1"){
        return 1;
    } else if (reg == "$2"){
        return 2;
    } else if (reg == "$3"){
        return 3;
    } else {
        std::cout << "There has been an error in regToBit" << std::endl;
        exit(1);
    }
    return -1;
}

uint8_t twoRegisters(std::string& name, std::string& reg1, std::string& reg2){
    uint8_t nameBits, reg1Bits, reg2Bits, finalByte;
    if(name == opNames[1]){
        nameBits = 0x1;
    } else if (name ==opNames[2]){
        nameBits = 0x2;
    } else if (name == opNames[3]){
        nameBits = 0x3;
    } else if (name == opNames[5]){
        nameBits = 0x5;
    } else {
        exit(1);
    }
    nameBits<<=4;
    reg1Bits = regToBit(reg1);
    reg2Bits = regToBit(reg2);
    reg1Bits<<=2;
    finalByte = reg1Bits | reg2Bits;
    finalByte = nameBits | finalByte;
    return finalByte;
}

uint8_t regThree(std::string& reg3){
    uint8_t reg3Bits = regToBit(reg3);
    reg3Bits<<=6;
    return reg3Bits;
}

uint8_t onlyImmediate(std::string& imm){
    uint8_t immBits;
    immBits = stringToInt(imm);
    return immBits;
}

uint8_t noImmediate(){
    return 0;
}

uint8_t nameAndReg1(std::string& name, std::string& reg1){
    uint8_t finalByte, nameBits;
    uint8_t reg1Bits = regToBit(reg1);
     if(name == opNames[6]){
           nameBits = 0x6;
       } else if (name ==opNames[7]){
           nameBits = 0x7;
       } else if (name == opNames[8]){
           nameBits = 0x8;
       } else {
           exit(1);
       }
    reg1Bits<<=2;
    nameBits<<=4;
    finalByte = nameBits | reg1Bits;
    return finalByte;
}

uint8_t nameOnly(std::string& name){
    uint8_t nameBits;
    nameBits = 4;
    nameBits <<=4;
    return nameBits;
}
