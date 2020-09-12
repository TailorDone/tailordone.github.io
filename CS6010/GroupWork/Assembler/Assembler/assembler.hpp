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

uint16_t twoRegistersAndImmediate(std::string& name, std::string& reg1, std::string& reg2, std::string& imm);

uint16_t threeRegisters(std::string& name, std::string& reg1, std::string& reg2, std::string& reg3);

uint16_t onlyImmediate(std::string& name, std::string& imm);

uint16_t oneRegister(std::string& name, std::string& reg1);
#endif /* assembler_hpp */
