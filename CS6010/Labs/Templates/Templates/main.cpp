//
//  main.cpp
//  Templates
//
//  Created by Taylor Dunn on 9/20/20.
//

#include <iostream>
#include "Template.h"

int main(int argc, const char * argv[]) {
    
    //Int Test
    Triple<int> intTest = Triple<int>(1, 2, 3);
    int intResult = intTest.sum();
    std::cout << "The result of the triple is: " << intResult << std::endl;
    std::cout << "Accessing the 2nd element is: " << intTest.b << std::endl;
    //String Test
    Triple<std::string> stringTest = Triple<std::string>("Coding ", "is ", "fun.");
    std::string stringResult = stringTest.sum();
    std::cout << "The result of the triple is: " << stringResult << std::endl;
    std::cout << "Accessing the 2nd element is: " << stringTest.b << std::endl;
    //Char Test
    Triple<char> charTest = Triple<char>('t', 'a', 'y');
    char charResult = charTest.sum();
    std::cout << "The result of the triple is: " << charResult << std::endl; //'t' = 116 'a' = 97 'y' = 121 116+97+121= 334. 334%128 = 78. 'N'= 78
    std::cout << "Accessing the 2nd element is: " << charTest.b << std::endl;
    //Double Test
    Triple<double> doubleTest = Triple<double>(3.14159, 2.71828, 1.61803);
    double doubleResult = doubleTest.sum();
    std::cout << "The result of the triple is: " << doubleResult << std::endl;
    std::cout << "Accessing the 2nd element is: " << doubleTest.b << std::endl;
    
    return 0;
}
