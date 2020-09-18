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
MyString::~MyString(){
    //clean up our MyString Object
    delete [] data;
    //data = nulptr; //unnecessary
}
