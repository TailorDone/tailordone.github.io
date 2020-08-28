//
//  main.cpp
//  FunctionPractice
//
//  Created by Taylor Dunn on 8/27/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

/**
 *Finds the hypotenuse of a triangle
 *
 *@param input1 Double representing a right angle side of a triangle
 *@param input2 Double representing a right angle side of a triangle
 *@return Returns a double representing the hypotenuse of the tirangle
 */
double hypotenuse(double input1, double input2){
    double hypotenuse = sqrt((input1*input1) + (input2*input2));
    return hypotenuse;
}
// You wouldn't want to get the input from inside the function as then you wouldn't know what your parameters are to actually call the funciton
// The velocity task into a funciton would be difficult because xVelocity and yVelocity require 2 different equations so you would have to create two functions for it to work.

/**
*Determines if a number is even
*
*@param number int A number to be tested
*@return Returns a boolean on whether the value was even or not
*/
bool isEven(int number){
    if (number % 2 == 0){
        return true;
    }
    return false;
}

/**
*Determines if a number isprime
*
*@param number int A number to be tested
*@return Returns a boolean on whether the value was prime or not
*/
bool isPrime (int number){
    if (number < 2) {
        return false;
    }
    int squareRoot = sqrt(number);
    for (int i = 2; i <= squareRoot; i ++){
        if ( number % i == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    double side1, side2, speed, angle, xVelocity, yVelocity;
    // Calculate the hypotenuse of a right triangle
    cout << "Input the right angle side lenghts of your triangle: " << endl;
    cin >> side1 >> side2;
    double hypotenuse = sqrt ((side1*side1) + (side2*side2));
    cout << "The hypotenuse of your triangle is: " << hypotenuse << endl;
    
    // Calculate the x and y velocity of a user
    cout << "We are going to calculate your velocity! What speed are you going?" << endl;
    cin >> speed;
    cout << "At what angle are you going in radians?" << endl;
    cin >> angle;
    xVelocity = speed * cos(angle);
    yVelocity = speed * sin(angle);
    cout << "Your x velocity is " << xVelocity << " and your y velocity is " << yVelocity << endl;
    
    // Calendar Function
    cout << "Testing the Calendar function";
    time_t result = time(nullptr);
    cout << asctime(localtime(&result))
    << result << " seconds since the Epoch" << endl;
    
    //Testing isEven function
    bool evebCheck1 = isEven(-4);
    cout << evebCheck1 << endl;
    bool evebCheck2 = isEven(13);
    cout << evebCheck2 << endl;
    bool evebCheck3 = isEven(256);
    cout << evebCheck3 << endl;
    
    //Testing isPrime function
    bool primeCheck1 = isPrime(-4);
    cout << primeCheck1 << endl;
    bool primeCheck2 = isPrime(13);
    cout << primeCheck2 << endl;
    bool primeCheck3 = isPrime(257);
    cout << primeCheck3 << endl;
    return 0;
}
