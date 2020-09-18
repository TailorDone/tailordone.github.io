//
//  Fraction.hpp
//  FractionClass
//
//  Created by Taylor Dunn & Tyler Speegle on 9/16/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef Fraction_hpp
#define Fraction_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "FractionTest.hpp"

class Fraction{
    long numerator;
    long denominator;
    void reduce();
    long GCD();
public:
    Fraction(); //Constructor for 0/1
    Fraction (long n, long d); //Constructor for n/d
    Fraction reciprocal(); //Returns a new fraction that is the reciprocal of this fraction
    std::string toString(); //Returns a string representation of this fraction
    double toDouble(); //Returns a double approximation of this fraction
    Fraction& operator+=(Fraction rhs);
    Fraction& operator-=(Fraction rhs);
    Fraction& operator*=(Fraction rhs);
    Fraction& operator/=(Fraction rhs);
    Fraction& operator-();
    bool operator==(Fraction rhs);
    bool operator<(Fraction rhs);
};
Fraction operator+(Fraction lhs, Fraction rhs);
Fraction operator-(Fraction lhs, Fraction rhs);
Fraction operator*(Fraction lhs, Fraction rhs);
Fraction operator/(Fraction lhs, Fraction rhs);
bool operator!=(Fraction& lhs, Fraction& rhs);
bool operator>(Fraction& lhs, Fraction& rhs);
bool operator<=(Fraction& lhs, Fraction& rhs);
bool operator>=(Fraction& lhs, Fraction& rhs);

#endif /* Fraction_hpp */
