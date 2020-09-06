//
//  analysis.cpp
//  BookAnalyzer
//
//  Created by Taylor Dunn on 9/4/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "analysis.hpp"

vector<string> readDataFromFile(ifstream& bookFile){
    string word;
    vector<string> bookWords;
    while (bookFile >> word){
        bookWords.push_back(word);
    }
    return bookWords;
}

int titleStartPoint(vector<string> bookWords){
    for(int i = 0; i < bookWords.size(); i++){
        if (bookWords[i] == "Title:"){
            return i;
        }
    }
    return -1;
}

int authorStartPoint(vector<string> bookWords, int start){
    for(int i = start; i < start + 100; i++){
        if (bookWords[i] == "Author:"){
            return i;
        }
    }
    return -1;
}

int releaseStartPoint(vector<string> bookWords, int start){
    for(int i = start; i < start + 100; i++){
        if (bookWords[i] == "Release"){
            return i;
        }
    }
    return -1;
}

string middleWords(vector<string> bookWords, int startIndex, int endIndex){
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

string titleAndAuthor(vector<string> bookWords){
    int titleIndex = titleStartPoint(bookWords);
    int authorIndex = authorStartPoint(bookWords, titleIndex);
    int releaseIndex = releaseStartPoint(bookWords,authorIndex);
    string title = middleWords(bookWords, titleIndex, authorIndex);
    string author = middleWords(bookWords, authorIndex, releaseIndex);
    return "Statistics for " + title + " by " + author + ":";
}

bool isVowel(char c){
    return (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u' ||tolower(c) == 'y');
}

bool isConsonant(char c){
    return (isVowel(c) == false && c != ' ');
}

int numWords(vector<string> s){
    return (int)s.size();
}

int numVowels(vector<string> s){
   int vowelCount = 0;
    for(int i = 0; i < s.size(); i++){
        for (char c : s[i]){
            if (isVowel(c) == true){
            vowelCount++;
            }
        }
    }
    return vowelCount;
}

int numConsonants(vector<string> s){
    int consonantCount = 0;
    for(int i = 0; i < s.size(); i++){
        for (char c : s[i]){
            if (isConsonant(c) == true)
            consonantCount++;
        }
    }
    return consonantCount;
}

int numChars(vector<string> s){
    return numConsonants(s) + numVowels(s);
}


//bool isPunctuation(char c){
//    return (c == '.' || c == '?' || c == '!' || c==',');
//}
