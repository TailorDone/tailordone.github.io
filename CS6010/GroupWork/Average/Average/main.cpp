//
//  main.cpp
//  Average
//
//  Created by Taylor Dunn and Kirk Hietpas on 8/25/20.
//  Copyright © 2020 Taylor Dunn. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int score1, score2, score3, score4, score5;
    std::cout << "Enter 5 assignment scores:\n";
    std::cin >> score1 >> score2 >> score3 >> score4 >> score5;
    double average = (score1 + score2 + score3 + score4 + score5) /5.0;
    std::cout << "Average: " << average << std::endl;
    return 0;
}
