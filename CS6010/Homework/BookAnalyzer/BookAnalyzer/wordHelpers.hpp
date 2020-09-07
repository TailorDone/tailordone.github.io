//
//  wordHelpers.hpp
//  BookAnalyzer
//
//  Created by Taylor Dunn on 9/7/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef wordHelpers_hpp
#define wordHelpers_hpp

#include <stdio.h>
#include "analysis.hpp"

//Returns whether or not the character is a vowel (including y)
bool isVowel(char& c);

//Returns whether or not the character is a consonant
bool isConsonant(char& c);

//Counts the number of words in the book
int numWords(const vector<string>& s);

//Counts the number of vowels in the book
int numVowels(const vector<string>& s, int endIndex);

int numConsonants(const vector<string>& s, int endIndex);

//Returns the number of consonants in the book
int numChars(const vector<string>& s, int endIndex);

//find the number of times the search word is found in the file
int numOfOccurences(const vector<string>& s, string searchWord);

int charNumber(const vector<string>& s, int endIndex);

int characterPercentage(const vector<string>& s, int endIndex);

vector<SearchWordInfo> wordLocation(const vector<string> s, string searchWord);

vector<string> wordLengths(const vector<string>& s);


#endif /* wordHelpers_hpp */
