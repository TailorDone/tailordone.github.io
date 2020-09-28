//
//  main.cpp
//  AssemblyAndMachineCode
//
//  Created by Taylor Dunn on 9/11/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

// c++ is a high-level language
//Has lots of concepts that are pretty abstract
//The compiler maps these concepts to the avaialable CPU instructions
//C++ compilers are very complicated
//Before HLLs people used to write in "assembly" which is human-readable machien code
//Assembly can be easily/directly translated to machine code
//No high-level concepts, even loops are not available
//Assmebly insturctions might look liek the following
//add $r1 $r2;
//equivalent to $r1 +=$r2 in c++. $r1 and $r2 are registers
//jump startOfLoop;
// jumps to a particular instruction in the code labeled with startOfLoop
//bne $r1 $r2 someLabel;
//"branch not equal" jump to someLabel if $r1 and $r2 are not equal, otherwise go to the next instruction
//addi $r1 500;
//add immediate, which means hardcoded value. $r1 +=500
//load $r1 $r2;
// $r2 is a pointer to memory. Copy the value on the other end of $r2's arrow into $r1
//Machine code, basically exactly the same as the assmebly on the previous slide, but expressed in a compact binary format
//No text names for the operations. The instruction names are replaces with "opcodes" which are short unsigned numbers
//registers, memory addresses, and immediate values are also stored in binary format
//The opcode, registers, etc. usually require less than 1 byte each to represent, so they are all packed together. The assembler has to use bit manipulation to squeeze things together
//An assembler is bascially a compiler for assembly code. it converts assembly code to machine code
//It's a much simpler program than a compiler

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
