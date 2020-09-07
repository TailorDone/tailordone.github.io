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



//Counts the number of words in the book
int numWords(const vector<string>& s);

//Determines a character (removes whitespace)
bool isCharacter(char& c);

//Returns the number of consonants in the book
int numChars(const vector<string>& s, int endIndex);

//Find the number of times the search word is found in the file
int numOfOccurences(const vector<string>& s, string searchWord);

//Finds the index for a particular character
int charNumber(const vector<string>& s, int endIndex);

//Calculates the percent of the way through the character is in the vector of strings.
int characterPercentage(const vector<string>& s, int endIndex);

//Finds the shortest [0], and then the longest word [1]
vector<string> wordLengths(const vector<string>& s);

#endif /* wordHelpers_hpp */
