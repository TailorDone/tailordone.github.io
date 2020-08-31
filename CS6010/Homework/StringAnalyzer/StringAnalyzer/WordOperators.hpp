//
//  WordOperators.hpp
//  StringAnalyzer
//
//  Created by Taylor Dunn on 8/31/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef WordOperators_hpp
#define WordOperators_hpp

#include <stdio.h>
#include <string>
using namespace std;

int numWords(string s);

int numSentences(string s);

int numVowels(string s);

int numConsonants(string s);

double averageVowelsPerWord(string s);

double readingLevel(string s);

#endif /* WordOperators_hpp */
