//
//  main.cpp
//  FractionClass
//
//  Created by Taylor Dunn & Tyler Speegle on 9/16/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include "Fraction.hpp"

int main(int argc, const char * argv[]) {
    TestConstructors();
    TestNegative();
    TestReduced();
    TestReciprocal();
    TestToDouble();
    TestPlus();
    Test("Approximating pi", 3.141592, ComputePi());
    TestDivision();
    TestMultiplication();
    TestSubtraction();
    TestEqualTo();
    TestLessThan();
    TestNotEqualTo();
    TestGreaterThan();
    TestLessThanOrEqualTo();
    TestGreaterThanOrEqualTo();
    return 0;
}
