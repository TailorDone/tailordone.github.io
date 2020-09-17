//
//  FractionTest.hpp
//  FractionClass
//
//  Created by Taylor Dunn on 9/16/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#ifndef FractionTest_hpp
#define FractionTest_hpp

#include <stdio.h>
#include "Fraction.hpp"

// Standard includes
#include <iostream>
#include <string>
// Also include math so we can use the pow and abs functions (see below)
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

bool CompareDoubles(double d1, double d);


/* Helper function for writing tests that compare strings.
 * Compares expected to result, and prints an error if they don't match.
 */
void Test(std::string message, std::string expected, std::string result);

/* Helper function for writing tests that compare doubles (overloaded version of the above)
 * Compares expected to result, and prints an error if they don't match.
 */
void Test(std::string message, double expected, double result);

/*
 * Helper function
 * Returns whether or not two doubles are "equivalent",
 * within a certain error bound.
 *
 * As we know, floating point numbers are incapable of
 * precisely representing certain values, so to compare
 * equality, we must tolerate some absolute difference.
 */
bool CompareDoubles(double d1, double d2);

/*
 * Basic constructor and toString tests
 */
void TestConstructors();


/*
 * Negative fraction tests
 */
void TestNegative();


/*
 * Reduced fraction tests
 */
void TestReduced();

/*
 * Reciprocal tests
 */
void TestReciprocal();

/*
 * Fraction addition tests
 */
void TestPlus();

void TestToDouble();

/*
 * Approximates pi using a summation of fractions.
 */
double ComputePi();

void TestDivision();

void TestMultiplication();

void TestSubtraction();

#endif /* FractionTest_hpp */
