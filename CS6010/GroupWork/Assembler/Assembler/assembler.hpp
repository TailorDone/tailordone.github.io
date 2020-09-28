//
//  assembler.hpp
//  Assembler
//
//  Created by Taylor Dunn on 9/11/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef assembler_hpp
#define assembler_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <cassert>
#include "Instruction.h"

//Takes a string and convert it to an int
uint8_t stringToInt(std::string& numberAsString);
//Takes an opCode name and converts it to an int
uint8_t nameToInt(std::string& name);
//Converts a reg value to a Byte
int8_t regToByte(std::string& reg);
//Creates a Byte with name, reg1, reg2
uint8_t twoRegisters(std::string& name, std::string& reg1, std::string& reg2);
//Creates a Byte with reg3 and 0's in the remaining 6 bits
uint8_t regThree(std::string& reg3);
//Creates a Byte for the value of the immediate
uint8_t onlyImmediate(std::string& imm);
//Creates a Byte of all 0's for no immediate and no reg 3
uint8_t noImmediate();
//Creates a Byte with name and reg1 and 00's in reg2
uint8_t nameAndReg1(std::string& name, std::string& reg1);
//Creates a Byte with name and 00's for reg1 and reg2
uint8_t nameOnly(std::string& name);


#endif /* assembler_hpp */
