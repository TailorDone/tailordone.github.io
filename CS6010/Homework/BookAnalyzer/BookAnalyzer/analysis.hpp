//
//  analysis.hpp
//  BookAnalyzer
//
//  Created by Taylor Dunn on 9/4/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef analysis_hpp
#define analysis_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


struct SearchWordInfo{
    int index;
    string beforeSearchWord;
    string searchWord;
    string afterSearchWord;
};

//Store all the words from bookFile in a vector of strings
vector<string> readDataFromFile(ifstream& bookFile);

//Finds where to start reading Title
int titleStartPoint(const vector<string>& bookWords);

//Find where to start reading the Author
int authorStartPoint(const vector<string>& bookWords, int& start);

//FInd where to start reading the Release Date
int releaseStartPoint(const vector<string>& bookWords, int& start);

//Finds the words between 2 indices
string middleWords(const vector<string>& bookWords, int& startIndex, int& endIndex);

//Returns the title and Author
string titleAndAuthor(const vector<string>& bookWords);

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



//UNUSED CODE
//Could include if you also wanted to remove standard puncutation from the file.
//Returns whether or not the character is . ? or !
//bool isPunctuation(char c);

//The total number of words in the file
//The total number of characters in the file (excluding whitespace).
//The shortest word in the book
//The longest word in the book
//The number of appearances, and locations of, the users key word (see below)

#endif /* analysis_hpp */
