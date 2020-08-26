//
//  main.cpp
//  ForLoopPractice
//
//  Created by Taylor Dunn on 8/26/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "Here is printing 1-10 using a for loop:" << std::endl;
    for (int i = 1; i <= 10; i ++){
        std::cout << i << std::endl;
    }
    std::cout << "Here is printing 1-10 using a while loop:" << std::endl;
    int j = 1;
    while (j <= 10) {
        std::cout << j << std::endl;
        j++;
    }
    //A for loop is more appropriate in this instance since it is a finite loop
    //Print all the numbers between two user integer inputs
    int startingNumber, endingNumber;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> startingNumber >> endingNumber;
    std::cout << "Here is a list of the numbers between your first and second input:" << std::endl;
    if (startingNumber <= endingNumber){
        while (startingNumber <= endingNumber) {
            std::cout << startingNumber << std::endl;
            startingNumber++;
        }
    } else {
        while (endingNumber <= startingNumber) {
            std::cout << startingNumber << std::endl;
            startingNumber--;
        }
    }
    //Print all the odd numbers using a loop and if statements
    std::cout << "Here is printing the odd numbers from 1-20 using if statements:" << std::endl;
    for (int i = 1; i <=20; i++){
        if (i%2 == 1){
            std::cout << i << std::endl;
        }
    }
    //Print all the odd numbers from 1-20 not using if statements
    std::cout << "Here is printing the odd numbers from 1-20 not using an if statements:" << std::endl;
    for (int i = 1; i <=20; i+=2){
        std::cout << i << std::endl;
    }
    
    //Sum numbers the user gives until the user enters a number that is less than 0
    int sum = 0;
    int userInput;
    std::cout << "Input any integer, positive or negative:" << std::endl;
    std::cin >> userInput;
    while (userInput >= 0){
        sum += userInput;
        std::cin >> userInput;
    }
    sum+= userInput;
    std::cout << "The sum of all the numbers you input is " << sum << std::endl;
    
    
    //Print a multiplication table for the numbers 1 to 5
    std::cout << "Here is a multiplication table for the numbers 1-5:" << std::endl;
    for (int row = 1; row <=5; row++){
        for (int col = 1; col <=5; col++){
            std::cout << row*col << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
