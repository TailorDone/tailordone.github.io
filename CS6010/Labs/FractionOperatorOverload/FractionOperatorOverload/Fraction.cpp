//
//  Fraction.cpp
//  FractionClass
//
//  Created by Taylor Dunn & Tyler Speegle on 9/16/20.
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

Fraction& Fraction::operator+=(Fraction rhs){
    long n= rhs.numerator*denominator; //Multiply right hand side by left hand denominator
    numerator *= rhs.denominator; //Multiply left hand numerator by right hand denominator
    denominator *= rhs.denominator; //Multiply left hand denominator by right hand denominator
    numerator += n;//Add the numerators, denominator stays as new left hand denominator
    reduce();
    return *this;
}

Fraction operator+(Fraction lhs, Fraction rhs){
    return lhs+=rhs;
}

Fraction& Fraction::operator-=(Fraction rhs){
    long n= rhs.numerator*denominator; //Multiply right hand side by left hand denominator
    numerator *= rhs.denominator; //Multiply left hand numerator by right hand denominator
    denominator *= rhs.denominator; //Multiply left hand denominator by right hand denominator
    numerator -= n;//Add the numerators, denominator stays as new left hand denominator
    reduce();
    return *this;
}

Fraction operator-(Fraction lhs, Fraction rhs){
    return lhs-=rhs;
}

Fraction& Fraction::operator*=(Fraction rhs){
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    reduce();
    return *this;
}

Fraction operator*(Fraction lhs, Fraction rhs){
    return lhs*=rhs;
}

Fraction& Fraction::operator/=(Fraction rhs){
    numerator *= rhs.reciprocal().numerator;
    denominator *= rhs.reciprocal().denominator;
    reduce();
    return *this;
}

Fraction operator/(Fraction lhs, Fraction rhs){
    return lhs/=rhs;
}

bool Fraction::operator==(Fraction rhs){
    reduce();
    rhs.reduce();
    return (numerator == rhs.numerator && denominator == rhs.denominator);
}

bool Fraction::operator<(Fraction rhs){
    long n = numerator;
    n *= rhs.denominator;
    rhs.numerator *= denominator;
    return (n < rhs.numerator);
}

bool operator!=(Fraction& lhs, Fraction& rhs){
    return(!(lhs==rhs));
}

bool operator>(Fraction& lhs, Fraction& rhs){
    return(rhs < lhs);
}

bool operator<=(Fraction& lhs, Fraction& rhs){
    return!(lhs>rhs);
}

bool operator>=(Fraction& lhs, Fraction& rhs){
    return !(lhs<rhs);
}

