//
//  main.cpp
//  Assembler
//
//  Created by Taylor Dunn on 9/11/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "assembler.hpp"

int main(int argc, const char * argv[]) {
     std::ifstream file(argv[1]);
       if(!file.is_open()){
           std::cout << "File not found" << std::endl;//If file is not found, error message sent and program is closed.
           exit(1);
       }
    std::string line;
    std::ofstream outs("outputFile.txt");
    while(std::getline(file,line)){
    std::istringstream splitter(line);
        std::string name, reg1, reg2, reg3, imm;
        splitter >> name;
    std::cout << name << std::endl;
        if (name == opNames[1] || name == opNames[2] || name == opNames[3]){
            splitter >> reg1;
            splitter >> reg2;
            splitter >> imm;
            std::cout << reg1 << reg2 << imm << std::endl;
            outs << std::hex << twoRegistersAndImmediate(name, reg1, reg2, imm) << std::endl;
        } else if(name == opNames[6] || name == opNames[7] || name == opNames[8]){
            splitter >> reg1;
            std::cout << reg1 << std::endl;
            outs << std::hex << oneRegister(name, reg1) << std::endl;
        } else if(name == opNames[4]){
            splitter >> imm;
            std::cout << imm << std::endl;
            outs << std::hex << onlyImmediate(name, imm) << std::endl;
        } else if(name == opNames[5]){
            splitter >> reg1;
            splitter >> reg2;
            splitter >> reg3;
            std::cout << reg1 << reg2 << reg3 << std::endl;
            outs << std::hex << threeRegisters(name, reg1,  reg2, reg3) << std::endl;
        } else {
            std::cout << "there has been a terrible mistake" << std::endl;
        }
    }
     return 0;
}
