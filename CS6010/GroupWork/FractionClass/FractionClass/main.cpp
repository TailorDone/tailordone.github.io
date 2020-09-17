//
//  main.cpp
//  FractionClass
//
//  Created by Taylor Dunn on 9/16/20.
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
    return 0;
}
