//
//  main.cpp
//  StringAnalyzer
//
//  Created by Taylor Dunn on 8/28/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <cctype> //include for the tolower method
using namespace std;

/*
 * Returns whether or not the character is . ? or !
 * @Param char A character
 * @Return Returns a boolean
 */
bool isTerminator(char c){
    if (c == '.' || c == '?' || c == '!'){
        return true;
    }
    return false;
}

/*
* Returns whether or not the character is . ? ! or ,
* @Param char A character
* @Return Returns a boolean
*/
bool isPunctuation(char c){
    if (isTerminator(c) == true || c == ','){
        return true;
    }
    return false;
}

/*
* Returns whether or not the character is a vowel (including y)
* @Param char A character
* @Return Returns a boolean
*/
bool isVowel(char c){
    if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u' ||tolower(c) == 'y'){
        return true;
    }
    return false;
}

/*
* Returns whether or not the character is a consonant
* @Param char A character
* @Return Returns a boolean
*/
bool isConsonant(char c){
    if (isVowel(c) == false && isPunctuation(c) == false && c != ' ') {
        return true;
    }
    return false;
}

 /*
 * Returns the number of words found in the string
 * @Param string s A string
 * @Return Returns an int representing the number of words
 */
int numWords(string s){
    int spaceCount = 0;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == ' '){
            spaceCount++;
        }
    }
    int wordCount = spaceCount + 1;
    return wordCount;
}

/*
* Returns the number of sentences found in the string
* @Param string s A string
* @Return Returns an int representing the number of sentences
*/
int numSentences(string s){
    int sentenceCount = 0;
    for(int i = 0; i < s.size(); i++){
        if (isTerminator(s[i]) == true){
            sentenceCount++;
        }
    }
    return sentenceCount;
}

/*
* Returns the number of vowles in the string
* @Param string s A string
* @Return Returns an int representing the number of vowels
*/
int numVowels(string s){
   int vowelCount = 0;
    for(int i = 0; i < s.size(); i++){
        if (isVowel(s[i]) == true){
            vowelCount++;
        }
    }
    return vowelCount;
}

/*
* Returns the number of consonants in the string
* @Param string s A string
* @Return Returns an int representing the number of consonants
*/
int numConsonants(string s){
    int consonantCount = 0;
    for(int i = 0; i < s.size(); i++){
        if (isConsonant(s[i]) == true){
            consonantCount++;
        }
    }
    return consonantCount;
}

/*
* Returns the average vowels per word
* @Param string s A string
* @Return Returns a double representing the average vowles per word
*/
double averageVowelsPerWord(string s){
    double average = (numVowels(s) * 1.0)/ numWords(s);
    return average;
}

/*
* Returns the reading level for the string
* @Param string s A string
* @Return Returns a double representing the average word length
*/
double readingLevel(string s){
    int totalChars = numConsonants(s) + numVowels(s);
    double averageWordLength = (totalChars * 1.0) / numWords(s);
    return averageWordLength;
}

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
