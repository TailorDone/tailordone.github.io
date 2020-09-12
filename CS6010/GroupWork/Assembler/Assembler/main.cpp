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
           std::cout << "File not found" << std::endl;
           exit(1);
       }
    std::string line;
    std::ofstream outs(argv[2]);
    while(std::getline(file,line)){
    std::istringstream splitter(line);
        std::string name, reg1, reg2, reg3, imm;
        splitter >> name;
    std::cout << name << std::endl;
        if (name == opNames[1] || name == opNames[2] || name == opNames[3]){
            splitter >> reg1;
            splitter >> reg2;
            splitter >> imm;
            outs.put(twoRegisters(name, reg1, reg2));
            outs.put(onlyImmediate(imm));
        } else if(name == opNames[7] || name == opNames[8]){
            splitter >> reg1;
            outs.put(nameAndReg1(name, reg1));
            outs.put(noImmediate());
        } else if(name == opNames[4]){
            splitter >> imm;
            outs.put(nameOnly(name));
            outs.put(onlyImmediate(imm));
        } else if(name == opNames[5] || name == opNames[6]){
            splitter >> reg1;
            splitter >> reg2;
            splitter >> reg3;
            outs.put(twoRegisters(name, reg1, reg2));
            outs.put(regThree(reg3));
        } else {
            std::cout << "Name not found." << std::endl;
            exit(1);
        }
    }
     return 0;
}
