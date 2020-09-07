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
    ifstream bookFile(argv[1]); //read bookName file from terminal
    if(!bookFile.is_open()){
        cout << "File not found" << endl; //If file is not found, error message sent and program is closed.
        exit(1);
    }
    string bookName = argv[1];
    string keyWord = (argv[2]); //read keyWord from terminal
    vector<string> bookWords = readDataFromFile(bookFile); //Takes all the words from the file and turns it into a vector of strings.
    printAnalysis(bookWords, bookName, keyWord);//Prints the Analysis for the given file
    return 0;
}
