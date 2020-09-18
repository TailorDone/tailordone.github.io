//
//  FractionTest.cpp
//  FractionClass
//
//  Created by Taylor Dunn & Tyler Speegle on 9/16/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "FractionTest.hpp"


bool CompareDoubles(double d1, double d);


/* Helper function for writing tests that compare strings.
 * Compares expected to result, and prints an error if they don't match.
 */
void Test(std::string message, std::string expected, std::string result)
{
  cout << "Test: " << message << endl;
  if(expected != result)
    cout << "\tFAILED, expected: \"" << expected << "\", got: \"" << result << "\"" << endl;
  else
    cout << "\tPASSED" << endl;
}

/* Helper function for writing tests that compare doubles (overloaded version of the above)
 * Compares expected to result, and prints an error if they don't match.
 */
void Test(std::string message, double expected, double result)
{
  cout << "Test: " << message << endl;
  if(!CompareDoubles(expected, result))
    cout << "\tFAILED, expected: " << expected << ", got: " << result << endl;
  else
    cout << "\tPASSED" << endl;
}


/*
 * Helper function
 * Returns whether or not two doubles are "equivalent",
 * within a certain error bound.
 *
 * As we know, floating point numbers are incapable of
 * precisely representing certain values, so to compare
 * equality, we must tolerate some absolute difference.
 */
bool CompareDoubles(double d1, double d2)
{
  return std::abs(d1 - d2) < 1e-6;
}

/*
 * Basic constructor and toString tests
 */
void TestConstructors(){
    std::string result = "";
    Fraction f1;
    result = f1.toString();
    Test("Default Constructor", "0/1", result);
  
    Fraction f2(1, 2);
    result = f2.toString();
    Test("Basic Constructor", "1/2", result);

    Fraction f3(-100, -20);
    result = f3.toString();
    Test("Two Negatives Constructor", "5/1", result);
    
    Fraction f4(3, -12);
    result = f4.toString();
    Test("Negative Denominator Constructor", "-1/4", result);
}


/*
 * Negative fraction tests
 */
void TestNegative(){
    std::string result = "";
    Fraction f1(-1, 2);
    result = f1.toString();
    Test("Negative Numerator", "-1/2", result);

    Fraction f2(1, -2);
    result = f2.toString();
    Test("Negative Denominator", "-1/2", result);

    Fraction f3(-1, -2);
    result = f3.toString();
    Test("Negative Numerator and Denominator", "1/2", result);

    Fraction f4(4, -16);
    result = f4.toString();
    Test("Negative Denominator and Reduce", "-1/4", result);

    Fraction f5(15, -10);
    result = f5.toString();
    Test("Larger Numerator, Negative Denominator And Reduce", "-3/2", result);
    
    Fraction f6(0, -13);
    result = f6.toString();
    Test("Zero Numerator, Negative Denominator", "0/13", result);
}


/*
 * Reduced fraction tests
 */
void TestReduced(){
  std::string result = "";
    Fraction f1(2, 4);
    result = f1.toString();
    Test("Reduce fraction (2/4)", "1/2", result);

    Fraction f2(15, -10);
    result = f2.toString();
    Test("Reduce fraction (15/-10)", "-3/2", result);
    
    Fraction f3(-12, -16);
    result = f3.toString();
    Test("Reduce fraction (-12/-16)", "3/4", result);
    
    Fraction f4(13, 13);
    result = f4.toString();
    Test("Reduce fraction (13/13)", "1/1", result);
}


/*
 * Reciprocal tests
 */
void TestReciprocal(){
    std::string result = "";
    Fraction f1(1, 3);
    f1 = f1.reciprocal();
    result = f1.toString();
    Test("Reciprocal of simple", "3/1", result);

    Fraction f2(-1, 2);
    f2 = f2.reciprocal();
    result = f2.toString();
    Test("Reciprocal of negative", "-2/1", result);

    Fraction f3(6, 2);
    f3 = f3.reciprocal();
    result = f3.toString();
    Test("Reciprocal of non-reduced", "1/3", result);

    Fraction f4(12, -2);
    f4 = f4.reciprocal();
    result = f4.toString();
    Test("Reciprocal of non-reduced with negative denominator", "-1/6", result);
    
    Fraction f5(-20, -30);
    f5 = f5.reciprocal();
    result = f5.toString();
    Test("Reciprocal of non-reduced, both negative", "3/2", result);
}

/*
 * Fraction addition tests
 */
void TestPlus(){
    std::string result = "";
    Fraction f1(4, 6);
    Fraction f2(3, 4);
  
    // Should result in 17/12
    Fraction f3 = f1+(f2);
    result = f3.toString();
    Test("Addition of non-reduced", "17/12", result);

    Fraction f4(-5, 10);
    Fraction f5(22, -6);
    Fraction f6 = f4+(f5);
    result = f6.toString();
    Test("Addition of non-reduced negatives", "-25/6", result);
    
    Fraction f7(3, 7);
    Fraction f8(8, -9);
    Fraction f9 = f7+(f8);
    result = f9.toString();
    Test("Addition of negative", "-29/63", result);
    
    Fraction f10(1, 2);
       Fraction f11(-1, 2);
       Fraction f12 = f10+(f11);
       result = f12.toString();
       Test("Addition of opposites", "0/4", result);
}

void TestToDouble()
{
  Fraction f1(1, 2);
  double result = f1.toDouble();
  Test("toDouble (1/2)", 0.5, result);

  Fraction f2(1, 3);
  result = f2.toDouble();
  Test("toDouble (1/3)", 1.0/3.0, result);
}

/*
 * Approximates pi using a summation of fractions.
 */
double ComputePi()
{
  Fraction sum;

  // We will only compute the first 4 terms
  // Note that even with long (64-bit) numbers,
  // the intermediate numbers required for fraction addition
  // become too large to represent if we go above k=4.
  for(long k = 0; k < 4; k++)
  {
    Fraction multiplier(1, pow(16, k));
    Fraction firstTerm(4, 8*k + 1);
    Fraction secondTerm(2, 8*k + 4);
    Fraction thirdTerm(1, 8*k + 5);
    Fraction fourthTerm(1, 8*k + 6);

    Fraction temp = firstTerm-(secondTerm);
    temp = temp-(thirdTerm);
    temp = temp-(fourthTerm);
 
    Fraction product = multiplier*(temp);

    sum = sum+(product);
  }
  
  return sum.toDouble();
}

void TestDivision(){
    std::string result = "";
    Fraction f1(4, 6);
    Fraction f2(3, 4);

    Fraction f3 = f1/(f2);
    result = f3.toString();
    Test("Division of non-reduced", "8/9", result);
    
    Fraction f4(-5, 10);
    Fraction f5(22, -6);
    Fraction f6 = f4/(f5);
    result = f6.toString();
    Test("Division  of non-reduced negatives", "3/22", result);
       
    Fraction f7(3, 7);
    Fraction f8(8, -9);
    Fraction f9 = f7/(f8);
    result = f9.toString();
    Test("Division of negative", "-27/56", result);
}

void TestMultiplication(){
    std::string result = "";
    Fraction f1(4, 6);
    Fraction f2(3, 4);

    Fraction f3 = f1*(f2);
    result = f3.toString();
    Test("Multiplication of non-reduced", "1/2", result);
    
    Fraction f4(-5, 10);
    Fraction f5(22, -6);
    Fraction f6 = f4*(f5);
    result = f6.toString();
    Test("Multiplication of non-reduced negatives", "11/6", result);
       
    Fraction f7(3, 7);
    Fraction f8(8, -9);
    Fraction f9 = f7*(f8);
    result = f9.toString();
    Test("Multiplication of negative", "-8/21", result);
}

void TestSubtraction(){
    std::string result = "";
    Fraction f1(4, 6);
    Fraction f2(3, 4);

    Fraction f3 = f1-(f2);
    result = f3.toString();
    Test("Minus of non-reduced", "-1/12", result);
    
    Fraction f4(-5, 10);
    Fraction f5(22, -6);
    Fraction f6 = f4-(f5);
    result = f6.toString();
    Test("Minus of non-reduced negatives", "19/6", result);
       
    Fraction f7(3, 7);
    Fraction f8(8, -9);
    Fraction f9 = f7-(f8);
    result = f9.toString();
    Test("Minus of negative", "83/63", result);
    
    Fraction f10(1, 2);
    Fraction f11(1, 2);
    Fraction f12 = f10-(f11);
    result = f12.toString();
    Test("Minus of opposites", "0/4", result);
}

void TestEqualTo(){
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(3, 6);
    Fraction f4(5, 6);
    bool result = f1 == f2;
    Test("Is 1/2 == 1/2", true, result);
    result = f1 == f3;
    Test("Is 1/2 == 3/6", true, result);
    result = f1 == f4;
    Test("Is 1/2 == 5/6", false, result);
}

void TestLessThan(){
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(0, 8);
    Fraction f4(-1, 4);
    bool result = f1 < f2;
    Test("Is 1/2 < 3/4", true, result);
    result = f3 < f4;
    Test("Is 0/8 < -1/4", false, result);
    result = f2 < f1;
    Test("Is 3/4 < 1/2", false, result);
}

void TestNotEqualTo(){
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(3, 6);
    Fraction f4(5, 6);
    bool result = f1 != f2;
    Test("Is 1/2 != 1/2", false, result);
    result = f1 != f3;
    Test("Is 1/2 != 3/6", false, result);
    result = f1 != f4;
    Test("Is 1/2 != 5/6", true, result);
}

void TestGreaterThan(){
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(0, 8);
    Fraction f4(-1, 4);
    bool result = f1 > f2;
    Test("Is 1/2 > 3/4", false, result);
    result = f3 > f4;
    Test("Is 0/8 > -1/4", true, result);
    result = f2 > f1;
    Test("Is 3/4 > 1/2", true, result);
}

void TestLessThanOrEqualTo(){
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(0, 8);
    Fraction f4(-1, 4);
    bool result = f1 <= f2;
    Test("Is 1/2 <= 3/4", true, result);
    result = f3 <= f4;
    Test("Is 0/8 <= -1/4", false, result);
    result = f2 <= f1;
    Test("Is 3/4 <= 1/2", false, result);
    result = f1 <= f1;
    Test("Is 1/2 <= 1/2", true, result);
}

void TestGreaterThanOrEqualTo(){
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(0, 8);
    Fraction f4(-1, 4);
    bool result = f1 >= f2;
    Test("Is 1/2 >= 3/4", false, result);
    result = f3 >= f4;
    Test("Is 0/8 >= -1/4", true, result);
    result = f2 >= f1;
    Test("Is 3/4 >= 1/2", true, result);
    result = f1 >= f1;
    Test("Is 1/2 >= 1/2", true, result);
}


void TestOpposite(){
    std::string result = "";
    Fraction f1(3, 7);
    Fraction f2 = -f1;
    result = f2.toString();
    Test("Opposite Operator", "-3/7", result);
    Fraction f3(-3, -7);
    Fraction f4 = -f3;
    result = f4.toString();
    Test("Opposite Operator", "-3/7", result);
    Fraction f5(3, -7);
    Fraction f6 = -f5;
    result = f6.toString();
    Test("Opposite Operator", "3/7", result);
    Fraction f7(0, -2);
    Fraction f8 = -f7;
    result = f8.toString();
    Test("Opposite Operator", "0/2", result);
}
