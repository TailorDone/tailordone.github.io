//
//  main.cpp
//  NumberConverter
//
//  Created by Taylor Dunn & Tyler Jette on 9/8/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <ctype.h>

int stringToInt(std::string numberAsString, int base){
    int numericValue;
    int total = 0;
    char c;
    if(base == 10){ //Decimal
        for(int i = 0; i < numberAsString.size(); i++){
            c = numberAsString[i];
            numericValue = c - '0';
            //std::cout << "This is iteration " << i << " and c is " << numericValue << std::endl;
            total+= pow(10,i) * numericValue;
        }
    }
    if(base == 2){ //Binary
        for(int i = 0; i < numberAsString.size(); i++){
            c = numberAsString[i];
            numericValue = c - '0';
            //std::cout << "This is iteration " << i << " and c is " << numericValue << std::endl;
            total+= pow(2,numberAsString.size()-i-1) * numericValue;
            //std::cout << total << std::endl;
        }
    }
    if(base == 16){//Hex
        std::string binary;
        std::string reverse;
        std::string combinedBinary;
        
        //Convert from Hex to Binary
        for(char c : numberAsString){
            c = tolower(c);
            //change string to numeric values
            if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f'){
                numericValue = c - 'a'+ 10;
            } else {
                numericValue = c - '0';
            }
            //std::cout << "The value of " << c << " is " << numericValue << std::endl;
            
            //Determine whether the remainder is even or odd through each divisibility of 2 and create a binary string
            while(numericValue > 0){
                if (numericValue % 2 == 0){
                    binary+="0";
                } else {
                    binary+="1";
                }
                numericValue = numericValue/2;
            }
            //std::cout << "before zeroes " << binary << std::endl;
            
            //Add zeros so binary length is 4
            if (binary.size()%4==0 && binary.size()==0){
                binary = "0000";
            } else if (binary.size()%4==1){
                binary+="000";
            } else if (binary.size()%4==2){
                binary+="00";
            } else if (binary.size()%4==3){
                binary+="0";
            } else {
                //Do nothing
            }
            
            //std::cout << "after zeroes " << binary << std::endl;
            //Reverse the values for the binary string
            for (char value : binary){
                reverse = value + reverse;
            }
            
            //std::cout << "reversed " << reverse << std::endl;
            //Insert the 4 new binary numbers to the end of the combinedBinary number
            combinedBinary+=reverse;
            std::cout << "combinedBinary" << combinedBinary << std::endl;
            reverse="";//Reset reverse
            binary = "";//Reset binary
        }
        
        //Convert from binary to decimal
        for(int i = 0; i < combinedBinary.size(); i++){
            c = combinedBinary[i];
            numericValue = c - '0';
            //std::cout << "This is iteration " << i << " and c is " << numericValue << std::endl;
            total+= pow(2,combinedBinary.size()-i-1) * numericValue;
            //std::cout << total << std::endl;
            }
    }
    return total;
}

int main(int argc, const char * argv[]) {
    int value = stringToInt("99",10);
    std::cout << value << std::endl;
    int value2 = stringToInt("1100",2);
    std::cout << value2 << std::endl;
    int value3 = stringToInt("FF", 16);
    std::cout << value3 << std::endl;
    int value4 = stringToInt("278", 16);
    std::cout << value4 << std::endl;
    return 0;
}
