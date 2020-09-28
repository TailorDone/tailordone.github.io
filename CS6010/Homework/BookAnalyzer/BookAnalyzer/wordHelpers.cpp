//
//  wordHelpers.cpp
//  BookAnalyzer
//
//  Created by Taylor Dunn on 9/7/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "wordHelpers.hpp"

int numWords(const vector<string>& s){
    return (int)s.size();
}

bool isCharacter(char& c) {
    return(c != ' ');
}

int numChars(const vector<string>& s, int endIndex){
    int charCount=0;
    for (int i = 0; i < endIndex; i++){
        for (char c : s[i]){
            if (isCharacter(c)){
                charCount++;
            }
        }
    }
    return charCount;
}

int numOfOccurences(const vector<string>& s, string searchWord){
    int occurenceCount = 0;
    for (string word : s){
        if (word == searchWord){
            occurenceCount++;
        }
    }
    return occurenceCount;
}



int charNumber(const vector<string>& s, int endIndex){
    return numChars(s, endIndex);
}

int characterPercentage(const vector<string>& s, int endIndex){
    int charPosition = charNumber(s, endIndex);
    int totalChars = numChars(s, (int)s.size());
    return 100 * charPosition / totalChars;
}

vector<string> wordLengths(const vector<string>& s){
    string shortest = s[0];
    string longest = s[1];
    if (shortest.size() > longest.size()){
        string temp = shortest;
        longest = shortest;
        temp = longest;
    }
    for(string word : s){
        if(word.size() < shortest.size()){
            shortest = word;
        }
        if(word.size() > longest.size()){
            longest = word;
        }
    }
    return {shortest, longest};
}
