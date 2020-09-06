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
    cout << numberOfWords << endl;
    int numberOfChars = numChars(bookWords);
    cout << numberOfChars << endl;
    
    return 0;
}
