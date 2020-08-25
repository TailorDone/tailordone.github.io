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
    int quarters, dimes, nickels, pennies;
    int totalChange = amountGiven - costOfItem;
    quarters = totalChange / 25;
    int remainderChange = totalChange;
    remainderChange = remainderChange - quarters * 25;
    dimes = remainderChange / 10;
    remainderChange = remainderChange - dimes * 10;
    nickels = remainderChange / 5;
    remainderChange = remainderChange - nickels * 5;
    pennies = remainderChange;
    std::cout << "Change: " << totalChange << " \nQuarters: " << quarters << "\nDimes: " << dimes << "\nNickles: " << nickels << "\nPennies: " << pennies << std::endl;
    return 0;
}
