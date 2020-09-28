//
//  main.cpp
//  BitWiseOperations
//
//  Created by Taylor Dunn on 9/10/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    //bitwise operators | &
    //aply logic operators on all pairs of corresponding bits at the same time
    //01101011
    //01011010  |
    //________
    //01111011
    //Applys 8 or's at the same time
    //01101011
    //01011010  &
    //________
    //01001010
    // ^ "eclusive or" which means !=
    //  a  b  a^b
    //  0  0   0
    //  0  1   1
    //  1  0   1
    //  1  1   0
    //01101011
    //01011010  ^
    //________
    //00110001
    // ~ "not negate" flips all bits
    // ~ 0110 1011 == 1001 0100
    
    int a = 2, b = 4; // ....00010 ...00100
    int c = a|b;
    // 010
    // 100
    // ____
    // 110 <<--- 6
    // works kind of like a +
    int x = 0xFC; // 1111 1100
    //assert(c==6);
    // <<
    // >>
    // shift operators
    // This will take your bit string and shift it over left or right
    // 0110 1010 >> 2 == (00)01 1010
    //     106               26
    // 0110 1010 << 2 == 1010 1000
    //    106               168 (+256) = 424
    
    //01100100 >> 2 == 0001 1001
    // 100               25
    //01100100 >> 1 == 0011 0010
    //each time you shift to the right, you divide by 2^x (integer division)
    //y >> x approximately y/2^x
    // y << x approximately y * 2^x
    //int low4bits (fill in top 28 bits with 0s)
    // The boolean identities
    // 1 | x == 1 output will always be 1 no matter what x is
    // 0 | x == x output will be x
    // 1 & x == x
    // 0 & x == 0
    // so if i want to keep bits the same
    // so we would need 000...00001111 & x --> 0xF & x;
    //int8_t b = -1; // bits 11111111
    //int i = b; // 32 bits  00000....11111111 255
    //Most significant bit
    //int8_t c = 1; // 00000001
    //int j = c; //00000...000000001
    //When you assign a smaller signed int type to a larger signed int type, the new bits copy the top bit of the smaller value
    // >> fills in with signed bit
    // 0000 0100 ~1
    //       11 <- carry
    // 1111 1011 flip
    // ________1add1
    // 1111 1100 =-4
    // >>1
    // 1111 1110 =-2
    //arithmetic right shift works like divide, even as negatives
    // if you're doing bitwise stuff, use explicitly size unsigned taypes
    // uint8_t, uint16_t, uint32_t, uint64_t
    //uint32_t * =0xDEAD BEEF;
    //-------v least significant bite
    //&x    EF  DE
    //&x+1  BE  AD
    //&x+2  AD  BE
    //&x+3  DE  EF
    //      ^------- most significant bite
    // this is called little endian. If we did column 2, that would be called big endian
    // "Endianness" which is saying which end comes first
    // Different CPU's use different endianness's
    //Intel x86 is little endian
    //PowerPC and ARM is big endian
    
    uint32_t z =  0xDEADBEEF; //2 nibbles makes a bite, so we need the DE
    //If we only want the top byte (DE) then we need to shift over 24
    uint8_t topByte = z >> 24; //we have 32
    std::cout << std::hex << +topByte << std::endl;
    //"We want to know which end comes first"
    uint8_t* px = (uint8_t*)&x;
    
    for (auto i : {0,1,2,3}){
        std::cout << std::hex << +(*(px+i))<<std::endl;
    }
    uint32_t test = -42;
    std::cout << test << std::endl;
    
    return 0;
    
}
