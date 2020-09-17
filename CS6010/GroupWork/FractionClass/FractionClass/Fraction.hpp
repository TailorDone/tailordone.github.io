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
    Fraction plus(Fraction rhs); //Returns a new fraction that is the result of the right hand side(rhs) fraction added to this fraction
    Fraction minus(Fraction rhs);//Returns a new fraction that is the result of the right hand side(rhs) fraction subtracted from this fraction
    Fraction times(Fraction rhs);//Returns a new fraction that is the result of the right hand side(rhs) fraction multiplied to this fraction
    Fraction dividedBy(Fraction rhs);//Returns a new fraction that is the result of the right hand side(rhs) fraction divided by this fraction
    Fraction reciprocal(); //Returns a new fraction that is the reciprocal of this fraction
    std::string toString(); //Returns a string representation of this fraction
    double toDouble(); //Returns a double approximation of this fraction
};

#endif /* Fraction_hpp */
