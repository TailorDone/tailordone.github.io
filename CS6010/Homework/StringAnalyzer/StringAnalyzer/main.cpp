//
//  main.cpp
//  StringAnalyzer
//
//  Created by Taylor Dunn on 8/28/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include "LetterHelpers.hpp"
#include "WordOperators.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int userIsInLoop = 1;
    while (userIsInLoop == 1){
        string input;
        cout << "Enter a string containing one or more sentences:" <<endl;
        getline(cin,input);
        cout << "Analysis:" << endl;
        cout << "Number of words: " << numWords(input) << endl;
        cout << "Number of sentences: " << numSentences(input) << endl;
        cout << "Number of vowels: " << numVowels(input) << endl;
        cout << "Number of consonants: " << numConsonants(input) << endl;
        cout << "Reading level (average word length): " << readingLevel(input) << endl;
        cout << "Average vowels per word: " << averageVowelsPerWord(input) << endl << endl;
    }
    return 0;
}
