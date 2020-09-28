//
//  main.cpp
//  CaesarCypher
//
//  Created by Taylor Dunn and Tyler Jette on 9/9/20.
//  Copyright © 2020 Tyler Jette and Taylor Dunn. All rights reserved.
//
//NOTE THIS IS PART 2 OF THE GROUP ASSIGNMENT FOR 9/9/20, Number and text representation
#include <iostream>
#include <cassert>
#include "Cipher.hpp"
using namespace std;

string encrypt(int n, string message){
    string encrypted = "";
    for(char c : message){
        if(c != ' '){
            //implicit looping mechanism for ascii table (97 - 122)
            if(c == '?' || c == '.' || c == ',' || c == '!'){//punctuation condition
                c = c;
            }else if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))){
                char a,z;
                if((c >= 'a') && (c <= 'z')){
                    a = 'a';
                    z = 'z';
                }else if((c >= 'A') && (c <= 'Z')){
                    a = 'A';
                    z = 'Z';
                }
                if(n > 0){ //message is being encrypted (command line arg is positive, cypher is moving right)
                    if((c + n) > z){ //char c is beyond the upper bounds of the alphabet
                        int overshot = n - ((z + 1) - c); //amount overshot
                        c = a + overshot;
                    }else{//within bounds
                        c = c + n;
                    }
                }else {//cypher is moving left
                    if((c + n) < a){ //c is beyond the lower bounds of the alphabet
                        int undershot = (a - 1) - (c + n); //amount undershot
                        c = z - undershot;
                    }else{//within bounds
                        c = c + n;
                    }
                }
            }//end of punctuation condition
        }//end of if non-empty space condition
        encrypted += c;
    }
    return encrypted;
}
