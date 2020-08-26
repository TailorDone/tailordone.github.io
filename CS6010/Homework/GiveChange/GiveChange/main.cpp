//
//  main.cpp
//  GiveChange
//
//  Created by Taylor Dunn on 8/25/20
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int costOfItem;
    std::cout << "What is the cost of your item in cents?\n";
    std::cin >> costOfItem;
    int amountGiven;
    std::cout <<"Enter the amount paid in cents?\n";
    std::cin >> amountGiven;
    //Coins that can be given by the machine
    int quarters, dimes, nickels, pennies;
    int totalChange = amountGiven - costOfItem;
    //Determine the number of quarters to give back
    quarters = totalChange / 25;
    int remainderChange = totalChange;
    //Change to be given after quarters have been determined
    remainderChange = totalChange % 25;
    //Determine the number of dimes to give back
    dimes = remainderChange / 10;
    //Change to be given after dimes have been determined
    remainderChange = remainderChange % 10;
    //Determine the number of nickles
    nickels = remainderChange / 5;
    //Determine the number of pennies
    pennies = remainderChange % 5;
    std::cout << "Change: " << totalChange << " \nQuarters: " << quarters << "\nDimes: " << dimes << "\nNickles: " << nickels << "\nPennies: " << pennies << std::endl;
    return 0;
}

//    Alternative Solution Not Using Mod
//    Replace line 22-26 with the following
//    remainderChange = remainderChange - quarters * 25;
//    dimes = remainderChange / 10;
//    remainderChange = remainderChange - dimes * 10;
//    nickels = remainderChange / 5;
//    remainderChange = remainderChange - nickels * 5;
//    pennies = remainderChange;
