//
//  main.cpp
//  OperatorOverloading
//
//  Created by Taylor Dunn on 9/17/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include "MyString.hpp"



int main(int argc, const char * argv[]) {
    //f.plus(g)
    //f+=g
    //"operator overloading"
    //cout << "hello world"
    //left shift
    //struct s{
    //}
    //S s;
    //cout << s;
    //Overloading, multiple functions with same name, but different parameters
    //FUNCTION VERSION
    //Fraction& operator+= (Fraction& f, Fraction g){} Need the reference for the left
    //f.changeSomehow(); return f
    //METHOD VERSION
    //Fraction& Fraction::operator +=(Fractiong){
    //numerator=;
    //denom=;
    //return *this; (this is a pointer, * dereferences. //Return a reference to the "left hand side"
    //If you have to access the private members you will want to use a method
    //f3=f1+f2;
    //Fraction Fraction::operator+(Fraciton lhs, Fraction rhs){
    //
    //}
    //Fraction operator+(Fraction lhs, Fraction rhs){ Plus equals a copy and returna copy
    //return lhs+=rhs;
    //}
    //Usually Write op= version as a method
    //takes rhs as parameter
    //lhs is this
    //modify this inside the method
    //return *this
    //They op version as a free function (not a method)
    //Take lhs by value
    //return lhs op= rhs as a copy
    //google "c++ operator overlaoding stack overflow"
    // Need 6 functions. ==, < make methods
    // >, !=,  <=,  >= probably just functions
    // cout << myFrac
    //Left of operator is this. so cout.opp<<(myFrac). This is an ostream class that we can't change.
    //std::ostream& operator<<(std::ostream& outs, const Frac& rhs){ Have to take it by reference
    // return outs}; Have to return by reference
    //((cout << f1) << f2)
    //in order for this to work, we need (cout<<f1) to give us a cout
    //[] method
    //Type MyVect::operator[](int index) const{ Type for our vector right now is an int. const means we won't change it, allows us to have 2 differen methods. one that changes a value, one that does not
    // return p[index];
    //cout<<mv[2]<<endl
    //mv[2] = 3; This won't work because you can't change your vector this way. it's give you a brand new int
    //But if we change the return type we can
    //Type& MyVect::operator[](int index){
    //return p[index];
    //} Actually modify what is on the heap. Need the bottom version to support mv[2]=3; But the bottom version sucks for printing
    // Because if you return the reference someone could modify it
    //op[] 2 versions with same body, 1 is const and returns a value, the other is not const, returns a reference
    //MyVec v(10;
    //Want to clear that heap by using v.freevector;
    //}the compiler knows that v's life has ended at this point. So we can have the compiler run some code when one of our objects is about to go out of scope. We want freevector to happen automatically
    //Destructor looks like a constructor, but it has been bitwise not ~className();
    //called automatically by compiler when a variable goes out of scope
    
    MyString s;
    std::cout << "empty string: " << s.cstring() << std::endl;
    MyString s2("hello world");
    std::cout << s2.cstring() << std::endl;
    MyString s3=s2;
    std::cout << s3.cstring() <<std::endl;
    return 0;
}
