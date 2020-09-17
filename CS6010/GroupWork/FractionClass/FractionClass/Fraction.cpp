//
//  Fraction.cpp
//  FractionClass
//
//  Created by Taylor Dunn on 9/16/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "Fraction.hpp"

void Fraction::reduce(){
    long gcd = GCD();
    numerator = numerator / gcd;
    denominator = denominator / gcd;
}

long Fraction::GCD(){
    long gcd = abs(numerator);
    if(numerator==0){ //If numerator is 0, return one, otherwise the denominator is returned as the gcd
        return 1;
    }
    long remainder = abs(denominator);
    while(remainder != 0) {
      long temp = remainder;
      remainder = gcd % remainder;
      gcd = temp;
    }
    return gcd;
}

Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction (long n, long d){
    assert(d!=0);
    numerator = n;
    denominator = d;
    if (denominator < 0){ //Changes both values to positive, or move the negative to the numerator
        numerator*=-1;
        denominator*=-1;
    }
    reduce();
}

Fraction Fraction::plus(Fraction rhs){
    Fraction result;
    long tempDenom = denominator;
    numerator *= rhs.denominator;
    denominator *= rhs.denominator;
    rhs.denominator *=tempDenom;
    rhs.numerator *= tempDenom;
    result.numerator = numerator + rhs.numerator;
    result.denominator = denominator;
    result.reduce();
    return result;
}

Fraction Fraction::minus(Fraction rhs){
    Fraction result;
    long tempDenom = denominator;
    numerator *= rhs.denominator;
    denominator *= rhs.denominator;
    rhs.denominator *=tempDenom;
    rhs.numerator *= tempDenom;
    result.numerator = numerator - rhs.numerator;
    result.denominator = denominator;
    result.reduce();
    return result;
}

Fraction Fraction::times(Fraction rhs){
    Fraction result;
    result.numerator = numerator * rhs.numerator;
    result.denominator = denominator * rhs.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::dividedBy(Fraction rhs){
    Fraction result;
    Fraction rhsRecip = rhs.reciprocal();
    result.numerator = numerator * rhsRecip.numerator;
    result.denominator = denominator * rhsRecip.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::reciprocal(){
    Fraction reciprocal = Fraction(denominator,numerator);
    return reciprocal;
}

std::string Fraction::toString(){
//    Want to change how simplification with 0 as numerator or 1 as denominator is printed.
//    if (numerator==0&& denominator!=0){
//        return "0";
//    } else if (denominator ==1){
//        return std::to_string(numerator);
//    } else{
    return std::to_string(numerator) + "/" + std::to_string(denominator);
//}
}

double Fraction::toDouble(){
    return (double)numerator/denominator;
}
