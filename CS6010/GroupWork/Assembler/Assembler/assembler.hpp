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
#include "Instruction.h"

uint8_t twoRegisters(std::string& name, std::string& reg1, std::string& reg2);

uint8_t regThree(std::string& reg3);

uint8_t onlyImmediate(std::string& imm);

uint8_t noImmediate();

uint8_t nameAndReg1(std::string& name, std::string& reg1);

uint8_t nameOnly(std::string& name);

#endif /* assembler_hpp */
