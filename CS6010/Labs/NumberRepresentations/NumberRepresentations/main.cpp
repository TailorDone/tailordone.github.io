//
//  main.cpp
//  NumberRepresentations
//
//  Created by Taylor Dunn on 9/9/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <cstdint>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <fstream>

bool approxEquals(double value1, double value2, double tolerance){
    return std::abs(value1-value2) < tolerance;
}

void printFiles(std::string fileTitle){
      std::ifstream ins(fileTitle);
      if(!ins.is_open()){
          std::cout << "File not found" << std::endl; //If file is not found, error message sent and program is closed.
          exit(1);
      }
      char c;
      while (ins >> c){
          std::cout << c; //Doesn't work with endl
      }
    std::cout << std::endl; //The first part compiles weird and not how I would expect, for example [ˈmaʳkʊskuːn] instead of Markus Kuhn
}

int main(int argc, const char * argv[]) {
    std::cout << "-----PART ONE-----" << std::endl;
    
    //Size of built in types
    std::cout << "The size of a char is " << sizeof(char) << " byte." << std::endl;
    std::cout << "The size of a bool is " << sizeof(bool) << " byte." << std::endl;
    std::cout << "The size of an int is " << sizeof(int) << " bytes." << std::endl;
    std::cout << "The size of a float is " << sizeof(float) << " bytes." <<  std::endl;
    std::cout << "The size of a double is " << sizeof(double) << " bytes." <<  std::endl<< std::endl;
    
    //Size of integer data types
    //Signed
    std::cout << "The size of int8_t is " << sizeof(int8_t) << " byte." <<  std::endl;
    int8_t min8 = 0x80; //[1000][0000] = -128 -128+ 0  +  0 + 0  + 0 + 0 + 0 + 0
    int8_t max8 = 0x7F; //[0111][1111] = 127     0+ 64 + 32 + 16 + 8 + 4 + 2 + 1
    int8_t min8Minus = 0x80-1;
    int8_t max8Plus = 0x7F+1;
    std::cout << "The min value for int8_t is " << +min8 << " and the max is " << +max8 << std::endl;
    std::cout << "The min minus 1 equals: " << +min8Minus << std::endl; //Loops back around
    std::cout << "The max plus 1 equals: " << +max8Plus  << std::endl << std::endl;;
    //Nothing is changing for undefined behavior sanitizer...
    
    //Unsigned
    //    std::cout << "The size of uint8_t is " << sizeof(uint8_t) << " byte." <<  std::endl;
    //    uint8_t min2 = 0x00; //[0000][0000] = 0
    //    uint8_t max2 = 0xFF; //[1111][1111] = 255
    //    std::cout << "The min value for uint8_t is " << +min2 << " and the max is " << +max2 << std::endl;
    //Signed
    std::cout << "The size of int16_t is " << sizeof(int16_t) << " bytes." <<  std::endl;
    int16_t min16 = 0x8000; //[1000][0000][0000][0000]
    int16_t max16 = 0x7FFF; //[0111][1111][1111][1111]
    std::cout << "The min value for int16_t is " << +min16 << " and the max is " << +max16 << std::endl;
    //Unsigned- Min: 0 (0x-FFFF) Max: 655535 (0xFFFF)
    //    std::cout << "The size of uint16_t is " << sizeof(uint16_t) << " bytes." <<  std::endl;
    //    uint16_t min4 = 0x0000;
    //    uint16_t max4 = 0xFFFF;
    //    std::cout << "The min value for uint16_t is " << +min4 << " and the max is " << +max4 << std::endl;
    //Signed
    std::cout << "The size of int64_t is " << sizeof(int64_t) << " bytes." <<  std::endl;
    int64_t min64 = 0x8000000000000000;
    int64_t max64 = 0x7FFFFFFFFFFFFFFF;
    std::cout << "The min value for int64_t is " << +min64 << " and the max is " << +max64 << std::endl << std::endl;
    
    std::cout << "-----PART TWO-----" << std::endl;
    float testFloat = .1 +.2;
    std::cout << testFloat << std::endl;
    //assert(testFloat==.3); Assertion fails
    std::cout << std::setprecision(18) << testFloat << std::endl;
    std::cout << "Does .1 + .2 approximately equal .3? " << approxEquals(.1, .2, .3) << std::endl << std::endl;
    
    std::cout << "----PART THREE----" << std::endl;
    std::string title = argv[1];
    printFiles(title);
    
    return 0;
}
