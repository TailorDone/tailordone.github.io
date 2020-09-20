//
//  Template.h
//  Templates
//
//  Created by Taylor Dunn on 9/20/20.
//

#ifndef Template_h
#define Template_h

template<typename T>
struct Triple{
    T a, b, c;
public:
    Triple(T a_, T b_, T c_);//Constructor
    T sum();
    Triple(std::vector<T> vect);
};

template<typename T>
Triple<T>::Triple(T a_, T b_, T c_){
    a = a_;
    b = b_;
    c = c_;
}

template<typename T>
T Triple<T>::sum(){
    return a+b+c;
}



#endif /* Template_h */
