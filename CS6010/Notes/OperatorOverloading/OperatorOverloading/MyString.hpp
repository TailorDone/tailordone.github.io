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
    const char* cstring() const;
    ~MyString(); //deconstructor
private:
    int length;
    char* data;
};
    
//const char* "hello world" //c string. Pointer to a constant character
    
#endif /* MyString_hpp */
