//
//  main.cpp
//  Structs
//
//  Created by Taylor Dunn on 9/1/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// built in types: int, bool, float, double, char
// structs - user defined data types

// Data for students
// Name - string
// ID number - int/string
// GPA - double
// Address - Address

//struct definition should go in a header file.
struct Student{
    string name;
    int ID;
    double GPA;
    //Address address;
};

Student enroll();

vector<Student> failingStudents(vector<Student> roster){
    return roster;
}

int main(int argc, const char * argv[]) {
    //student s;
    //s.name = "Ben" would refer to the name part of student object s
    // cout << s.ID << endl;
    //object.fieldName
    //vector (student) roster;
    //roster[0].name
    //roster.front().name;
    
    Student taylor;
    taylor.name = "Taylor";
    taylor.ID = 0671007;
    taylor.GPA = 3.99;
//    taylor.address = some Address Variable;
    
    Student scott {"Scott", 12345, 3.88};
    
    cout << taylor.name << endl;
    cout << scott.ID << endl;
    
    return 0;
}

//in header files, x code adds #ifndef SOMEHTING #define SOMETHING --your code-- #endif
//these are called include guards

//main.cpp a.hpp b.hpp a.cpp b.cpp
//inside of b, you have struct B{}
//inside of a, you have int f(B b)
//you'll have a compiler error. you have to #include "b.hpp"
//Inside main we need a B b; so we need to #include "b.hpp"
// f(b) can't be called because we need a's header file #include "a.hpp"
// we can now get rid of the b.hpp becuase a will call that for us anyway.
// we only want it once or else it will copy twice
// include guards. if we've seen this file already, don't copy and paste it again
// alternatively  you'll see #pragma once //same things ad ifndef, define, endif
