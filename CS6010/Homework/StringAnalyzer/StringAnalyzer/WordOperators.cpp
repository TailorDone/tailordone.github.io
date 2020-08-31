//
//  WordOperators.cpp
//  StringAnalyzer
//
//  Created by Taylor Dunn on 8/31/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "WordOperators.hpp"
#include "LetterHelpers.hpp"
#include <iostream>
using namespace std;


 /*
 * Returns the number of words found in the string
 * @Param string s A string
 * @Return Returns an int representing the number of words
 */
int numWords(string s){
    int spaceCount = 0;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == ' '){
            spaceCount++;
        }
    }
    int wordCount = spaceCount + 1;
    return wordCount;
}

/*
* Returns the number of sentences found in the string
* @Param string s A string
* @Return Returns an int representing the number of sentences
*/
int numSentences(string s){
    int sentenceCount = 0;
    for(int i = 0; i < s.size(); i++){
        if (isTerminator(s[i]) == true){
            sentenceCount++;
        }
    }
    return sentenceCount;
}

/*
* Returns the number of vowles in the string
* @Param string s A string
* @Return Returns an int representing the number of vowels
*/
int numVowels(string s){
   int vowelCount = 0;
    for(int i = 0; i < s.size(); i++){
        if (isVowel(s[i]) == true){
            vowelCount++;
        }
    }
    return vowelCount;
}

/*
* Returns the number of consonants in the string
* @Param string s A string
* @Return Returns an int representing the number of consonants
*/
int numConsonants(string s){
    int consonantCount = 0;
    for(int i = 0; i < s.size(); i++){
        if (isConsonant(s[i]) == true){
            consonantCount++;
        }
    }
    return consonantCount;
}

/*
* Returns the average vowels per word
* @Param string s A string
* @Return Returns a double representing the average vowles per word
*/
double averageVowelsPerWord(string s){
    double average = (numVowels(s) * 1.0)/ numWords(s);
    return average;
}

/*
* Returns the reading level for the string
* @Param string s A string
* @Return Returns a double representing the average word length
*/
double readingLevel(string s){
    int totalChars = numConsonants(s) + numVowels(s);
    double averageWordLength = (totalChars * 1.0) / numWords(s);
    return averageWordLength;
}
