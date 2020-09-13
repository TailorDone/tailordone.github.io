//
//  assembler.cpp
//  Assembler
//
//  Created by Taylor Dunn on 9/11/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "assembler.hpp"

uint8_t stringToInt(std::string numberAsString) {
    int numericValue, total = 0, sign = 1, startIndex = 0;
    char c;
    //Determines if the number is negative
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

uint8_t nameToInt(std::string& name){
    for(int i = 1; i < 9; i++){
        if (name == opNames[i]){
            return i;
        }
    }
    std::cout << "Illegal name input. Name not found.";
    exit(1);
    return -1;
}

int8_t regToByte(std::string& reg){
    for(char c : reg){
        if (c <= '3' && c >= '0'){
            return c - '0';
        }
    }
    std::cout << "Illegal reg input. Out of bounds." << std::endl;
    exit(1);
    return -1;
}
    

uint8_t twoRegisters(std::string& name, std::string& reg1, std::string& reg2){
    uint8_t reg1Bits, reg2Bits, finalByte;
    uint8_t opCode = nameToInt(name);
    opCode<<=4;
    reg1Bits = regToByte(reg1);
    reg2Bits = regToByte(reg2);
    reg1Bits<<=2;
    finalByte = reg1Bits | reg2Bits;
    finalByte = finalByte | opCode;
    return finalByte;
}

uint8_t regThree(std::string& reg3){
    uint8_t reg3Bits = regToByte(reg3);
    reg3Bits<<=6;
    reg3Bits = reg3Bits & -1;
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
    uint8_t finalByte;
    uint8_t reg1Bits = regToByte(reg1);
    uint8_t opCode = nameToInt(name);
    reg1Bits<<=2;
    opCode<<=4;
    finalByte = opCode | reg1Bits;
    return finalByte;
}

uint8_t nameOnly(std::string& name){
    uint8_t nameBits;
    nameBits = 4;
    nameBits <<=4;
    return nameBits;
}

