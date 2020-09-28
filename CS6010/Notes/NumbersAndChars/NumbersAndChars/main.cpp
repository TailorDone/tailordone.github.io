//
//  main.cpp
//  NumbersAndChars
//
//  Created by Taylor Dunn on 9/9/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    //Each hexdigit (hexit, nibble) == 4 bits
    //Decimal //   Hex  // Binary
    //   0    //   0    //  0000
    //   1    //   1    //  0001
    //   2    //   2    //  0010
    //   3    //   3    //  0011
    //   4    //   4    //  0100
    //   5    //   5    //  0101
    //   6    //   6    //  0110
    //   7    //   7    //  0111
    //   8    //   8    //  1000
    //   9    //   9    //  1001
    //   10   //   A    //  1010
    //   11   //   B    //  1011
    //   12   //   C    //  1100
    //   13   //   D    //  1101
    //   14   //   E    //  1110
    //   15   //   F    //  1111
    //
    //Formula:
    //total+= pow(base,numberAsString.size()-i-1) * numericValue;
    //
    //Lets say you had 826dec -->> Hex
    //x/16^i will give you the digits in the i place
    //
    //To show the computer we are writing in hex we would do 0x5DB4
    //To show the computer we are writing in octal we would do 0123
    //Terrible codding. Try to avoid octal.
    //
    //How to do negatives
    //you could have your first value be a "signed bit"
    //This isn't a good idea
    //00...00 "+0"
    //10...00 "-0"
    //This is called one's compliment
    //What we actually use is 2's compliment
    //1[0101001]
    //^-- That one represents a normal power of 2, but negative (-128 place)
    //Still a sign bit. if it's a 1, it's a negative number
    //11111111 is acutally -1 (-128+127)
    //So if it starts with a 1, it's a negative
    //Arithmetic: just do it, ignore the sign
    //Example: 0001(positive 1)
    //       + 1111 (negative 1)
    //       ________
    //         0000
    //Carry. the last one loses it's carry.
    //For example with an int, a signed int would have a 1 at the front
    //And unsigned it would could have a 1 to represent the positive
    //
    //The negation trick
    //x to negative x
    //flip all the bits and add 1
    //if x is 1
    //0001
    //1110 then add 1 = 1111 (boom -1)
    // -128  64  32  16  8  4  2  1
    //   1   0   0   0   0  0  0  0  smallest number -128
    //   0   1   1   1   1  1  1  1  largest number 127
    //256 posibilities 2^8
    //More negatives than positives which means it's not symmetric
    //Negative trick on negative 128
    //  0    1   1   1  1  1  1  1 flip
    // add one
    //  1   0    0   0  0  0  0  0
    //You end up with -128 again
    //-128 -1
    //  0   1   1   1   1  1  1  1
    // We get 127. When we get to the end, we wrap around
    //1 followed by 0's is the smallest possible number
    //0 followed by 1's i the largest possible number
    // all 0's is 0. all 1's is negative 1
    //negation trick (flip the values add 1) is good to know
    //
    //Floating Point #s
    //Binary version of scientific notation
    //something times 10^e
    //something >=1 but <10
    // 4.567       x   10     ^e
    //{significand} {base} {exponent}
    //Normalized scientific notation
    // Binary
    // significand only 1's and 0, base 2, exponent whatever
    //in binary, we know what the first point will be so we don't need to store it
    //0.01001 should be 1.001 *2 e-2
    //(-1) 1.101010
    //     {mantissa}
    //There is a sign bit as well
    //Floating point has 3 pieces
    //Sign, Mantissa, exponent
    //{ 1 bit}  {       23 bits        }  {    8 bits    }  <-- too scale (ish)
    //            ^--- about 6,7 decimal digits    ^-- gives us -128 to 127 exponents
    //floating point because the decimal moves
    //for a dobule
    // {1 bit}   { 52 bits } {11}
    //most of the bits go to the mantisa, so most of the bits go to the precision
    //if you set the exponents to the maximum value, then it becomes infinity.
    //+inf -inf  nan (not a number)
    //nan would be sqrt-1, 0/0, inf-inf
    //nan is contageous. everything nan touches becomes nan. which is nice because you can trace back.
    //0.1 cannot be represented as a floating point
    //Every operation you do with a floating point would be the same if you did it with an infinite number of bits and then rounded to the nearest floating point number
    //This means, don't set floating points equal to each other
    //.1+.2==.3 is not true because of the way the rounding works
    //For floating points we check if things are close
    //abs (a-b) < some tolerance
    //characters are stored as an int type
    //so if you add, subtract, or multiply that works
    // 8 bit (1 byte) integer types
    // When printing, we use a table called the ascii table to turn numbers into letters
    // Unicode is an extention to the Ascii table. Much bigger table that allows for international characters, as well as emojis
    //UTF.8 Ascii stuff works the same as without unicode, use more bytes for higher unicode numbers
    return 0;
}
