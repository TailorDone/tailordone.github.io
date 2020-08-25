//
//  main.cpp
//  RoadTripCalculator
//
//  Created by Taylor Dunn on 8/25/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int distance;
    std::cout << "How many miles will you be traveling? ";
    std::cin >> distance;
    int milesPerGallon;
    std::cout << "How many miles per gallon does your car get? ";
    std::cin >> milesPerGallon;
    double pricePerGallon;
    std::cout << "What is the price per gallon for gas? $";
    std::cin >> pricePerGallon;
    double numberOfGallons = distance / milesPerGallon;
    double totalCost = numberOfGallons * pricePerGallon;
    std::cout << "The total cost of your trip will be $" << totalCost << ".\n";
    return 0;
}
