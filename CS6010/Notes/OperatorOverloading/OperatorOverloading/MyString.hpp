//
//  MyString.hpp
//  OperatorOverloading
//
//  Created by Taylor Dunn on 9/17/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <stdio.h>

class MyString{
public:
    MyString();
    MyString(const char* str);
    
    //The rule of 3
    MyString(MyString& rhs);// copy constructor, make a brand new copy
    MyString& operator=(const MyString& rhs); //make a copy when the lhs already exists
    ~MyString(); //deconstructor
    //If your class has pointers, you probably need the rule of 3.
    
    
    const char* cstring() const;//return the pointer
private:
    int length;
    char* data;
};
    
//const char* "hello world" //c string. Pointer to a constant character
    
#endif /* MyString_hpp */
