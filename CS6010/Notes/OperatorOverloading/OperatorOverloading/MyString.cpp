//
//  MyString.cpp
//  OperatorOverloading
//
//  Created by Taylor Dunn on 9/17/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "MyString.hpp"
#include <cstring>

MyString::MyString(const char* str)
:length(strlen(str)) //fills it before you even start running the function
{
    //length = strlen(str); //Goes until it his the null terminator. Array will be one longer because it holds that
    data = new char[length+1]; //+1 includes the "null terminator" or 0-byte
    for(int i = 0; i <= length; i ++){ //<= include the null terminator
        data[i] = str[i];
    }
}

MyString::MyString()
:MyString("") //Calling our const char* constructor with ""
{}

const char* MyString::cstring()const{
    return data;
}

//Destructor
MyString::~MyString(){
    //clean up our MyString Object
    delete [] data;
    //data = nulptr; //unnecessary
}

//Have to pass by reference
//Copy constructor
MyString::MyString(MyString& rhs){
    length = rhs.length;
    data = new char[length+1];
    for (int i = 0; i <= length; i++){
        data[i] = rhs.data[i];
    }
}

MyString& MyString::operator=(const MyString& rhs){
    //Copy over data to a new array
    if(this == &rhs){
        return *this; //Checks if this and rhs are the same object;
    }
    //I know this and rhs are different objects
    delete [] data; //deletes the left hand side array. deallocates the original memomry place
    data = new char[rhs.length+1]; //the plus 1 is the null byte
    length = rhs.length;
    for(int i = 0; i <=length; i++){
        data[i] = rhs.data[i];
    }
    //Deallocate the old array
    return *this; //this is a pointer *this is a reference. this goes at the end of every op=
    
    //Could also store the old pointer and delete at the end.
    // char* newData = new char[rhs.length+1];
    //length = rhs.length;
//    for(int i = 0; i <=length; i++){
//        newData[i] = rhs.data[i];
//    }
//    delete [] data;
//    data = newData;
//    return *this;
}
