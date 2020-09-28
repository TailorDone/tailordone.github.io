//
//  main.cpp
//  MapAndSet
//
//  Created by Taylor Dunn & Tyler Speegle on 9/23/20.
//

#include <iostream>
#include <fstream>
#include <set>
#include <map>

int main(int argc, const char * argv[]) {
    std::ifstream bookFile(argv[1]); //read bookName file from terminal
    if(!bookFile.is_open()){
        std::cout << "File not found" << std::endl; //If file is not found, error message sent and program is closed.
        exit(1);
    }
    std::map<std::string, int> countOfWord;
    std::set<std::string> uniqueWords;
    std::string word;
    while (bookFile >> word){
        uniqueWords.insert(word);
        countOfWord[word] += 1;
    }
    int size = (int)uniqueWords.size();
    std::cout << "There are: " << size << " unique words!" << std::endl;
    std::cout << "Weltering appears " << countOfWord["weltering"] << " times!" << std::endl;
    return 0;
}
