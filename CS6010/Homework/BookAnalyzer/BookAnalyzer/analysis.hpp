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

//Find where to start reading the Release Date
int releaseStartPoint(const vector<string>& bookWords, int& start);

//Finds the words between 2 indices
string middleWords(const vector<string>& bookWords, int& startIndex, int& endIndex);

//Returns the Title and Author
string titleAndAuthor(const vector<string>& bookWords);

//Finds where a word is located and stores the index as well as the word before and after the index.
vector<SearchWordInfo> wordLocation(const vector<string> s, string searchWord);

//Prints the analysis for the book
void printAnalysis(vector<string> bookWords, string bookName, string keyWord);

#endif /* analysis_hpp */
