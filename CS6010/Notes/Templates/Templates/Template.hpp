//
//  Template.hpp
//  Templates
//
//  Created by Taylor Dunn on 9/20/20.
//

#ifndef Template_hpp
#define Template_hpp

#include <stdio.h>

template<typename T>
struct Holder{
    T x;
    T myMethod() const;
};

template<typename T>
T Holder<T>::myMethod() const{
    //return x*2; //But you can't multiply a string with an int
    //Some methods don't work with all the types, but only finds out once your run your code with a given type
    return x+x;
}

//Pushback is going to take a T instead of int. [] will return T.
#endif /* Template_hpp */
