//
//  wordHelpers.cpp
//  BookAnalyzer
//
//  Created by Taylor Dunn on 9/7/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "wordHelpers.hpp"

bool isVowel(char& c){
    return (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u' ||tolower(c) == 'y');
}

bool isConsonant(char& c){
    return (isVowel(c) == false && c != ' ');
}

int numWords(const vector<string>& s){
    return (int)s.size();
}

int numVowels(const vector<string>& s, int endIndex){
   int vowelCount = 0;
    for(int i = 0; i < endIndex; i++){
        for (char c : s[i]){
            if (isVowel(c) == true){
            vowelCount++;
            }
        }
    }
    return vowelCount;
}

int numConsonants(const vector<string>& s, int endIndex){
    int consonantCount = 0;
    for(int i = 0; i < endIndex; i++){
        for (char c : s[i]){
            if (isConsonant(c) == true)
            consonantCount++;
        }
    }
    return consonantCount;
}

int numChars(const vector<string>& s, int endIndex){
    return numConsonants(s, endIndex) + numVowels(s, endIndex);
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

vector<SearchWordInfo> wordLocation(const vector<string> s, string searchWord){
    SearchWordInfo wordInfo;
    vector<SearchWordInfo> allInfo;
    for (int i = 0; i < s.size(); i ++){
        if(s[i] == searchWord){
            wordInfo.index = i;
            wordInfo.beforeSearchWord = s[i-1];
            wordInfo.searchWord = s[i];
            wordInfo.afterSearchWord = s[i+1];
            allInfo.push_back(wordInfo);
        }
    }
    return allInfo;
}

int charNumber(const vector<string>& s, int endIndex){
    return numChars(s, endIndex);
}

int characterPercentage(const vector<string>& s, int endIndex){
    int charPosition = charNumber(s, endIndex);
    int totalChars = numChars(s, s.size());
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
