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
    int amountPaid;
    std::cout <<"Enter the amount paid in cents?\n";
    std::cin >> amountPaid;
    //  If user enters a negative value, the program will quit.
    if (amountPaid < 0 || costOfItem < 0) {
        std::cout << "Cannot enter a negative value. Please try again." << std::endl;
        return 1;
    }
    int totalChange = amountPaid - costOfItem;
    //  If user is short funds the vending machine will tell user how much more funds are needed to complete the purchase and will quit.
    if (amountPaid < costOfItem){
        std::cout << "Insufficient funds! Please insert " << -totalChange << " cents more." << std::endl;
        return 1;
    }
    //  These variables are "obvious" but I'm trying to avoid using magic numbers.
    int startingQuarters = 2;
    int startingDimes = 2;
    int startingNickels = 2;
    int startingPennies = 2;
    int quarterWorth = 25;
    int dimeWorth = 10;
    int nickelWorth = 5;
    int machineChange = startingQuarters * quarterWorth + startingDimes * dimeWorth + startingNickels * nickelWorth + startingPennies;
    /*  Ends program if change is greater than what the machine is currently holding or
    *   if the user needs an amount that ends in a 3, 4, 8, or 9
    *   which is impossible to give back with only 2 pennies.
    */
    if (totalChange > machineChange || totalChange % 10 == 3 || totalChange % 10 == 4 || totalChange % 10 == 8 || totalChange % 10 == 9){
        std::cout <<"Unable to return change, out of coins!" << std::endl;
        return 1;
    }
    int quarters = totalChange / 25;
    int remainderChange = totalChange;
    remainderChange = totalChange % 25;
    int dimes = remainderChange / 10;
    remainderChange = remainderChange % 10;
    int nickels = remainderChange / 5;
    int pennies = remainderChange % 5;
    //If the quarters needed is 3, the machine will actually give 2 quarters, 2 dimes, and 1 nickel.
    if (quarters == 3){
        quarters = 2;
        dimes = 2;
        //There is a chance a nickle has already been given
        nickels +=1;
    }
    std::cout << "Change: " << totalChange << " \nQuarters: " << quarters << "\nDimes: " << dimes << "\nNickles: " << nickels << "\nPennies: " << pennies << std::endl;
    return 0;
}
