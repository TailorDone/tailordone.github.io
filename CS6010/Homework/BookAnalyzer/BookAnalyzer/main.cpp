//
//  main.cpp
//  BookAnalyzer
//
//  Created by Taylor Dunn on 9/4/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "analysis.hpp"

int main(int argc, const char * argv[]) {
    //read bookName file from terminal
    ifstream bookFile(argv[1]);
    //If file is not found, error message sent and program is closed.
    if(!bookFile.is_open()){
        cout << "File not found" << endl;
        exit(1);
    }
    string bookName = argv[1];
    //read keyWord from terminal
    string keyWord = (argv[2]);
    vector<string> bookWords = readDataFromFile(bookFile);
    //cout << "First word: " << bookWords[2] << " Last word: " << bookWords[bookWords.size()-1] << endl;
    string bookInfo = titleAndAuthor(bookWords);
    cout << bookInfo << endl;
    int numberOfWords = numWords(bookWords);
    cout << "Number of words: " << numberOfWords << endl;
    int numberOfChars = numChars(bookWords, bookWords.size());
    cout << "Number of characters: " << numberOfChars << endl;
    vector<string> shortAndLong = wordLengths(bookWords);
//    cout << "The shortest word is \"" << shortAndLong[0] << "\" and the longest word is \"" << shortAndLong[1] << "\"" << endl;
    string searchWord = "weltering";
    vector<SearchWordInfo> info = wordLocation(bookWords, searchWord);
    cout << "The word " << searchWord << " appears " << info.size() << " times:" << endl;
    for (SearchWordInfo location : info){
        cout << " at " << characterPercentage(bookWords, location.index) << "%: " << "\"" << location.beforeSearchWord << " " << location.searchWord << " " << location.afterSearchWord << "\"" << endl;
        
    }
    return 0;
}
