//
//  analysis.cpp
//  BookAnalyzer
//
//  Created by Taylor Dunn on 9/4/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "analysis.hpp"
#include "wordHelpers.hpp"

vector<string> readDataFromFile(ifstream& bookFile){
    string word;
    vector<string> bookWords;
    while (bookFile >> word){
        bookWords.push_back(word);
    }
    return bookWords;
}

int titleStartPoint(const vector<string>& bookWords){
    for(int i = 0; i < bookWords.size(); i++){
        if (bookWords[i] == "Title:"){
            return i;
        }
    }
    return -1;
}

int authorStartPoint(const vector<string>& bookWords, int& start){
    for(int i = start; i < start + 100; i++){
        if (bookWords[i] == "Author:"){
            return i;
        }
    }
    return -1;
}

int releaseStartPoint(const vector<string>& bookWords, int& start){
    for(int i = start; i < start + 100; i++){
        if (bookWords[i] == "Release"){
            return i;
        }
    }
    return -1;
}

string middleWords(const vector<string>& bookWords, int& startIndex, int& endIndex){
    if (startIndex == -1 || endIndex == -1){
        return "unknown";
    }
    string middleWords = "";
    for (int i = startIndex + 1; i < endIndex; i++){
        middleWords += bookWords[i];
        if (i != endIndex-1){
            middleWords += " ";
        }
    }
    return middleWords;
}

string titleAndAuthor(const vector<string>& bookWords){
    int titleIndex = titleStartPoint(bookWords);
    int authorIndex = authorStartPoint(bookWords, titleIndex);
    int releaseIndex = releaseStartPoint(bookWords,authorIndex);
    string title = middleWords(bookWords, titleIndex, authorIndex);
    string author = middleWords(bookWords, authorIndex, releaseIndex);
    return "Statistics for " + title + " by " + author + ":";
}

vector<SearchWordInfo> wordLocation(const vector<string> s, string searchWord){
    SearchWordInfo wordInfo;
    vector<SearchWordInfo> allInfo;
    for (int i = 0; i < s.size(); i ++){
        if (s[i] == searchWord){
            wordInfo.index = i;
            wordInfo.beforeSearchWord = s[i-1];
            wordInfo.searchWord = s[i]; //if i=0 || i=s.size()-1 then a blank space will print before or after respectively due to the print out in analysis.
            wordInfo.afterSearchWord = s[i+1];
            allInfo.push_back(wordInfo);
        }
    }
    return allInfo;
}

void printAnalysis(vector<string> bookWords, string bookName, string keyWord){
    string bookInfo = titleAndAuthor(bookWords);
    cout << bookInfo << endl;
    int numberOfWords = numWords(bookWords);
    cout << "Number of words: " << numberOfWords << endl;
    int numberOfChars = numChars(bookWords, (int)bookWords.size());
    cout << "Number of characters: " << numberOfChars << endl;
    vector<string> shortAndLong = wordLengths(bookWords);
    cout << "The shortest word is \"" << shortAndLong[0] << "\" and the longest word is \"" << shortAndLong[1] << "\"" << endl;
    vector<SearchWordInfo> info = wordLocation(bookWords, keyWord);
    cout << "The word " << keyWord << " appears " << info.size() << " times:" << endl;
    for (SearchWordInfo location : info){
        cout << " at " << characterPercentage(bookWords, location.index) << "%: " << "\"" << location.beforeSearchWord << " " << location.searchWord << " " << location.afterSearchWord << "\"" << endl;
    }
}






