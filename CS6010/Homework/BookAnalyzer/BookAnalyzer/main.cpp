//
//  main.cpp
//  BookAnalyzer
//
//  Created by Taylor Dunn on 9/4/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "analysis.hpp"
#include "wordHelpers.hpp"

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
    //Takes all the words from the file and turns it into a vector of strings.
    vector<string> bookWords = readDataFromFile(bookFile);
    //Prints the Analysis for the given file
    printAnalysis(bookWords, bookName, keyWord);
    return 0;
}
