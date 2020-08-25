//
//  main.cpp
//  GiveChange
//
//  Created by Taylor Dunn on 8/25/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int costOfItem;
    std::cout << "What is the cost of your item in cents? ";
    std::cin >> costOfItem;
    int amountGiven;
    std::cout <<"Enter the amount paid in cents? ";
    std::cin >> amountGiven;
    int quarters, dimes, nickels, pennies;
    int initialChange = amountGiven - costOfItem;
    quarters = initialChange / 25;
    int changeBack = initialChange;
    changeBack = changeBack - quarters * 25;
    dimes = changeBack / 10;
    changeBack = changeBack - dimes * 10;
    nickels = changeBack / 5;
    changeBack = changeBack - nickels * 5;
    pennies = changeBack;
    std::cout << "Change: " << initialChange << " \nQuarters: " << quarters << "\nDimes: " << dimes << "\nNickles: " << nickels << "\nPennies: " << pennies << "\n";
    return 0;
}
