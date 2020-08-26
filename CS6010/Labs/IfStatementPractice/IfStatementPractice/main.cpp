//
//  main.cpp
//  IfStatementPractice
//
//  Created by Taylor Dunn on 8/25/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    //Part 1
    int age;
    std::cout << "What is your age?\n";
    std::cin >> age;
    //See if user is old enough to vote
    if(age>=18){
        std::cout << "Congrats! You are old enough to vote!\n";
    } else {
        std::cout << "Bad news! you aren't old enough to vote.\n";
    }
    //See if user is old enough to run for senate
    if(age>=30){
        std::cout << "Congrats! You are old enough to run for senate!\n";
    } else {
        std::cout << "Bad news! you aren't old enough to run for senate.\n";
    }
    //Finds out the generation of the user
    if(age>=80){
        std::cout << "You are part of the greatest generation!\n";
    } else if(age >= 60) {
        std::cout << "You are a baby boomer!\n";
    } else if(age >= 40) {
        std::cout << "You are in generation X!\n";
    } else if(age >= 20) {
        std::cout << "You are a millennial!\n";
    } else {
        std::cout << "You are an iKid!\n";
    }
    
    //Part 2
    char weekdayResponse, holidayResponse, childrenResponse;
    std::cout << "Is today a weekday? (Y/N)\n";
    std::cin >> weekdayResponse;
    std::cout << "Is today a holiday? (Y/N)\n";
    std::cin >> holidayResponse;
    std::cout << "Do you have young children at home? (Y/N)\n";
    std::cin >> childrenResponse;
    bool isWeekday, isHoliday, hasChildren;
    //Determine if it's a weekday
    if (weekdayResponse == 'Y' || weekdayResponse == 'y'){
        isWeekday = true;
    } else {
        isWeekday = false;
    }
    //Determine if it's a holiday
    if (holidayResponse == 'Y' || holidayResponse == 'y'){
        isHoliday = true;
    } else {
        isHoliday = false;
    }
    //Determine if the user has children
    if (childrenResponse == 'Y' || childrenResponse == 'y'){
        hasChildren = true;
    } else {
        hasChildren = false;
    }
    //Determine whether or not the user will be sleeping in
    if (isHoliday == true && hasChildren == false){
        std::cout << "It's a holiday! Enjoy sleeping in!\n";
    } else if (isWeekday == true || hasChildren == true){
        std::cout << "You won't be sleeping in today!\n";
    } else {
        std::cout << "You get to sleep in today!\n";
    }
}
