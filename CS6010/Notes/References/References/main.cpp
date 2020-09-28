//
//  main.cpp
//  References
//
//  Created by Taylor Dunn on 9/2/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <string>

//void swap(int a, int b){
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int f(int x);
//copies parameter onto f's stack
//pass by value, pass by copy
int g(int& x);
//refering to a variable on teh caller's stack frame
//pass by reference

struct HUGE{
    //lots of stuff
};

//This is passing a copy into the function
void print(HUGE huge){
    //std::cout << huge << ...
}

//Pass by const reference
//This means don't make a copy, I'll work on the original, but I promise not to change it
void print(const HUGE& huge){
    //....
}

int main(int argc, const char * argv[]) {
    int x = 1;
    int y = 2;
    swap (x,y);
    // This wouldn't work because of scope. So we need something
    // We are going to use & - "reference"
    // int& "reference to int" "int reference"
    // refer to an existing variable. it doesn't create new storage. it creates a reference
    assert(x==2);
    assert(y==1);
    // We use &params to modify variables in someone else's stack frame
    // void shuffleDeck(Deck& deck)
    //in main shuffleDeck(Deck)
    //"indirection" refering to something that is somewhere else
    //for example shuffleDeck(deck), shuffleDeck(deck)
    std::string name = "Ben"; //We want to turn it to lowercase
    for (char c: name){
        c=tolower(c);
    }
    std::cout << name << std::endl;
    //This won't work because it is changing the name of a copy
    //We want to refer to the actual characters in the string, so we want a reference
    //use references in for each loop to change the values in our list/string
    std::string name2 = "Ben"; //We want to turn it to lowercase
    for (char& c: name2){
        c=tolower(c);
    }
    std::cout << name2 << std::endl;
    
    //magic word is const this means "i promise not to change this, and the compiler will check for me"
    //3 ways to pass parameters
    //by value (copy)
    //by ref no copy, intend to change original
    //by const ref no copy, no change
    //PBV if want to change a copy, maybe to return it
    //prefer PBCR if the object is "big" (for now, that's anything that is not a primitive. strings, vectors, structs)
    //int rand() returns random number between 0 and huge. want 0 to 51, rand % 5
    
    std::cout<<RAND_MAX;
    return 0;
}
