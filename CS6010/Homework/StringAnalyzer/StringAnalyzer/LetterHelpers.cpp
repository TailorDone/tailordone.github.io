//
//  LetterHelpers.cpp
//  StringAnalyzer
//
//  Created by Taylor Dunn on 8/31/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "LetterHelpers.hpp"
#include <cctype> //include for the tolower method
using namespace std;

/*
 * Returns whether or not the character is . ? or !
 * @Param char A character
 * @Return Returns a boolean
 */
bool isTerminator(char c){
    return (c == '.' || c == '?' || c == '!');
}

/*
* Returns whether or not the character is . ? ! or ,
* @Param char A character
* @Return Returns a boolean
*/
bool isPunctuation(char c){
   return (isTerminator(c) == true || c == ',');
}

/*
* Returns whether or not the character is a vowel (including y)
* @Param char A character
* @Return Returns a boolean
*/
bool isVowel(char c){
    return (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u' ||tolower(c) == 'y');
}

/*
* Returns whether or not the character is a consonant
* @Param char A character
* @Return Returns a boolean
*/
bool isConsonant(char c){
    return (isVowel(c) == false && isPunctuation(c) == false && c != ' ');
}
