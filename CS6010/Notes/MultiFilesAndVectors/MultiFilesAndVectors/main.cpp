//
//  main.cpp
//  MultiFilesAndVectors
//
//  Created by Taylor Dunn on 8/31/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <cassert> // <> means look in system directory.
#include "sf.hpp" //"" means look in folder the cpp file is in
#include <vector>
using namespace std;
 

// Does the code compile? If yes, it's working in the sense that the syntax is correct. Does it run without crashing? After this it's up to us to verify that our code works.
// Check input output pairs. Check f (input) == output?
// Going to use "assert" # include<cassert>
//assert (condition); if condition is true: nothing happens. else: crash
//Test suite, range of inputs. range of outputs. fast. deterministic

int multBy5(int number){
    int fiveTimes = 5 * number;
    return fiveTimes;
}

bool isVowel(char c){
    if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u' ||tolower(c) == 'y'){
        return true;
    }
    return false;
}
//Holds your tests
void runTests(){
    assert(multBy5(3) == 15);
    assert(isVowel('Y'));
    assert(!isVowel('b'));
}

//Multi-File Projects
//Put functions up top, then main, then what they do.
// We can move it out of the same file.
//sf.hpp only has declaration int somefunction(int x, int y);
//sf.cpp

//int someFunction(int x, int y);

void printIntVector(vector<int> vi){
    for (int i = 0; i < vi.size() ; i++){
        cout << vi[i] << endl;
    }
}

int main(int argc, const char * argv[]) {
    int x = someFunction(2,3);
    cout << x << endl;
    runTests(); //Runs your tests
    vector <int> vi; //list of ints
    vector <float> vf; //list of floats
    vector <vector<string>> vvs; //list of list of strings
   // int n = vi.size();
   // int first = vi[0];
    //float last = vf.back();
    vi.push_back(10); //(this adds 10 to the end (grows) and grows the list by 1)
    vi.pop_back(); //shrinks size by 1
    vector <int> loopingVec; //empty, size() == 0
    for (int i = 0; i < 10; i ++) {
        loopingVec.push_back(i);
    }
    printIntVector(loopingVec);
    //vector<int> initial(10); //initial size == 10, filled with 0's
    //for (j = 0; j < initial.size(); j++) {
     //   initial(j);
    //}
    
    //for loops suck. for each element in my vector is better.
    //for each f in vf. for each element in my vector.
    for(float f: vf){
        cout << f << endl;
    }
    
    return 0;
}

//int someFunction(int x, int y){
    //return x+y;
//}

// compiling .cpp file
// object file .o file
// requires function declrations only to call external functions
// we are going to get main. (definition for main. refers to in someFunc(int, int))
// o out and sf. o (definition for int somefunc(int, int))
// linking takes .0 files and puts them together to an executable program
// compile each .cpp file into corresponding .o file. then link all .o files into "exectuable"
// then we can run the executable
// compiler and linker clang++
// For the terminal:
// $ clang++ -c main.cpp (-c, compiles. This produces main.o)
// $ clang++ -c sf.cpp (produces sf.o)
// $ clang++ main.o sf.o (produces a.out, which is our executable file)
// $ clang++ -o myProgram (Gives it a name. -o "what to call the output")
// $ ./myProgram (./a.out)

// Lists of data. "Arrays". c++ "vectors"
// # include <vector>
